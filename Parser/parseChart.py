#!/usr/bin/env python3

import sys
import os
import logging
import argparse

# https://docs.google.com/document/d/1v2v0U-9HQ5qHeccpExDOLJ5CMPZZ3QytPmAG5WF0Kzs/mobilebasic
# (tickEnd - tickStart) / resolution * 60.0 (seconds per minute) / bpm

"""
Default Variables (can be changed via command line arguments):
    BULK: If True, the script will parse all .chart files in the specified folder.
    INPUT_FILE: Path to the input .chart file, typically located in the same directory as this script (if BULK == False)
    INPUT_FOLDER_PATH: Path to the folder containing the .chart files to parse (if BULK == True).
    OUTPUT_FILE: Path for the output structured file, which will be in the format of a .h Arduino header file.
    DIFFICULTY_TO_PARSE: 
        .chart files contain note information for multiple difficulties, this variable
        selects which difficulty to parse since we only output a single version of the song
        to be used by the ArduinoHero game.
    SAMPLING_RATE: 
        Notes sampled from .chart file @ Resolution * Sampling Rate.
        Basically, this is sample every quarter note (SAMPLING_RATE == 1), eighth note (SAMPLING_RATE == 2), etc.
"""
BULK = True
INPUT_FOLDER_PATH = os.path.join(
    os.path.dirname(__file__), 'chorus_charts')
OUTPUT_FOLDER_PATH = os.path.join(
    os.path.dirname(__file__), 'parsed_charts')
INPUT_FILE = os.path.join(os.path.dirname(__file__), 'song.chart')
DIFFICULTY_TO_PARSE = 'ExpertSingle'
# 1 = quarter note, 2 = eighth note, 4 = sixteenth note, etc.
SAMPLING_RATE = [1, 2, 4]

"""
notes.chart format:
[Song]
{
  Name = "Shake It Off (Taylor's Version)"
  Artist = "Taylor Swift"
  Charter = "Daintii"
  Album = "1989 (Taylor's Version)"
  Year = ", 2023"
  Offset = 0
  Resolution = 192
  Player2 = bass
  Difficulty = 0
  PreviewStart = 0
  PreviewEnd = 0
  Genre = "Pop"
  MediaType = "hey hey hey"
  MusicStream = "song.ogg"
}
[SyncTrack]
{
  0 = TS 4
  0 = B 159506
  1536 = B 160000
}
[EasySingle]
{
  4608 = N 1 0
  4800 = N 1 0
  4992 = N 1 0
  5376 = N 1 0
  5568 = N 1 0
  5760 = N 1 0
  6048 = N 2 0
  6336 = N 2 0
  6528 = N 2 0
  6912 = N 2 0
}
"""

"""
chart.h should output an instance of the following struct:
struct Song {
  char *name;
  char *artist;
  char *charter;
  char *album;
  int year;
  char *genre;
  char *filename;
   
  // Each byte represents a beat
  // 00000000 = no note
  // 00011111 = 5 fret note
  byte *beats[];
  beats_length;
  
  // The BPMs in order that they appear in the song
  'bpm_values': [], // [155, 160, ...] (value to change the bpm to)
   bpm_values_length;
  
  // The index in beats[] that the bpm changes occurs at (parallel array to bpm_values)
  'bpm_change_indexes': [], # [0, 815]
};
"""

"""
This is necessary because we must ensure the fields are outputted in the
same order as they are defined in the struct.
"""
SONG_STRUCT_FIELDS = [
    "name",
    "artist",
    "charter",
    "album",
    "year",
    "genre",
    "filename",
    "resolution",
    "sampling_rate",
    "bpm_values",
    "bpm_change_indexes",
    "bpm_values_length",
    "beats",
    "beats_length"
]


def parse_chart_file(filepath, difficulty, sampling_rate):
    """
    Parses the .chart file and extracts relevant information based on the specified difficulty.
    """
    song_data = {}
    current_section = None
    with open(filepath, 'r', encoding='utf-8-sig') as file:
        for line in file:
            line = line.strip()
            if line.startswith('['):
                current_section = line[1:-1]
                song_data[current_section] = []
            elif '=' in line and current_section:
                key, value = line.split('=', 1)
                song_data[current_section].append(
                    (key.strip(), value.strip().strip('"')))
            elif current_section == difficulty and '=' in line:
                song_data[current_section].append(line)

    return song_data


def process_bpm_changes(song_data, resolution, sample_rate):
    """
    Processes BPM changes and calculates the indexes in the ArduinoHero beats[] array 
    at which these changes occur.
    """
    bpm_values = []
    bpm_change_indexes = []

    # Extract BPM change events from SyncTrack data
    sync_track_data = song_data.get('SyncTrack', [])

    for tick, event in sync_track_data:
        if 'B' in event:
            # The event is something like "B 159506"
            # Splitting the string and getting the BPM part
            bpm_str = event.split(' ')[1]
            tick = int(tick)
            bpm = float(bpm_str) / 1000  # Converting to actual BPM value

            # Calculate the index of the beat (in the beats[] list we will make next) of the BPM change
            index = tick / (resolution * sample_rate)

            # Log a warning if the index is not an integer and round it
            if not index.is_integer():
                logging.warning(
                    f"BPM change index is not an integer, rounding: {index} to {round(index)}")
                index = round(index)

            bpm_values.append(bpm)
            # Convert to int for whole number
            bpm_change_indexes.append(int(index))

    return bpm_values, bpm_change_indexes


def process_arudinohero_beats(song_data, resolution, sampling_rate, difficulty):
    beats = []
    # Mapping of note types to their bit positions
    note_bit_positions = {
        '0': 0b000001,  # Green
        '1': 0b000010,  # Red
        '2': 0b000100,  # Yellow
        '3': 0b001000,  # Blue
        '4': 0b010000,  # Orange
        '7': 0b100000,  # Open note
    }

    # Adjusting ticks_per_sample based on sampling_rate
    ticks_per_sample = resolution / sampling_rate
    current_sample_ticks = 0
    current_sample_byte = 0b000000

    for beat in song_data[difficulty]:
        timestamp, note_info = beat
        timestamp = int(timestamp)

        # Check if the timestamp exceeds the next sample point
        while timestamp >= current_sample_ticks + ticks_per_sample:
            beats.append(current_sample_byte)
            current_sample_byte = 0b000000
            current_sample_ticks += ticks_per_sample

        # Process the note
        note_type = note_info.split()[1]
        note_byte = note_bit_positions.get(note_type, 0b000000)
        current_sample_byte |= note_byte

    # Append the last sample if it has notes
    if current_sample_byte != 0b000000:
        beats.append(current_sample_byte)

    print(f"Number of beats: {len(beats)}")
    return beats


def create_arduinohero_struct(song_data, sampling_rate, difficulty):
    """
    Converts the parsed song data into the struct format.
    """

    # Extract general song info
    song_info = song_data['Song']
    song_info_dict = {k: v for k, v in song_info}

    # Extract year and convert to int
    year_str = song_info_dict.get('Year', '0').strip()
    year = 0
    for char in year_str:
        if char.isdigit():
            year = year * 10 + int(char)

    # Convert resolution to int
    resolution = int(song_info_dict.get('Resolution', '192')
                     )  # Using a default value if not found

    # Initialize struct fields
    struct_song = {
        'name': song_info_dict.get('Name', ''),
        'artist': song_info_dict.get('Artist', ''),
        'charter': song_info_dict.get('Charter', ''),
        'album': song_info_dict.get('Album', ''),
        'year': year,
        'genre': song_info_dict.get('Genre', ''),
        'filename': song_info_dict.get('MusicStream', ''),

        'resolution': resolution,
        'sampling_rate': sampling_rate,

        'beats': [],  # [0b00000001, 0b00000010, ...]
        # Each byte represents a beat.
        # Each beat is not necessarily a quarter note,
        # it depends on the sampling rate & resolution.
        # (00000000 = no note (rest), 00011111 = 5 fret note, etc.)
        'beats_length': 0,  # The length of the beats array

        'bpm_values': [],  # [155, 160]
        # (The BPMs in order that they appear in the song)
        'bpm_values_length': 0,  # The length of the beats array
        'bpm_change_indexes': [],  # [0, 815, ...]
        # The index in beats[] that the bpm changes occurs at
        # (parallel array to bpm_values)

    }

    struct_song['bpm_values'], struct_song['bpm_change_indexes'] = process_bpm_changes(
        song_data, resolution, sampling_rate)
    struct_song['bpm_values_length'] = len(struct_song['bpm_values'])

    # Process and generate the necessary information for an ArduinoHero beat chart
    struct_song['beats'] = process_arudinohero_beats(
        song_data, resolution, sampling_rate, difficulty)
    struct_song['beats_length'] = len(struct_song['beats'])

    return struct_song


def write_to_file(struct_song, output_file, song_var_name):
    """
    Writes the converted song data into a .h file in struct format.
    """

    print(f"Writing to {output_file}...")

    # Create the necessary directories if they don't exist
    os.makedirs(os.path.dirname(output_file), exist_ok=True)

    with open(output_file, 'w') as file:
        file.write('#include "song.h"\n\n')
        file.write(f'Song {song_var_name} = {{\n')
        for key in SONG_STRUCT_FIELDS:
            value = struct_song[key]
            if isinstance(value, str):
                file.write(f'  /* {key} */ "{value}",\n')
            elif isinstance(value, int):
                file.write(f'  /* {key} */ {value},\n')
            elif isinstance(value, list):
                array_str = ', '.join(str(elem) for elem in value)
                if key == 'beats':
                    file.write(f'  /* beats */ (byte[]) {{{array_str}}},\n')
                elif key == 'bpm_values':
                    file.write(
                        f'  /* bpm_values */ (float[]) {{{array_str}}},\n')
                elif key == 'bpm_change_indexes':
                    file.write(
                        f'  /* bpm_change_indexes */ (int[]) {{{array_str}}},\n')
        file.write('};\n')


def parse_chart(input_file, output_path, difficulty, sampling_rate):
    """
    Parses the specified .chart file and outputs a .h file in struct format.
    """
    song_data = parse_chart_file(input_file, difficulty, sampling_rate)
    struct_song = create_arduinohero_struct(
        song_data, sampling_rate, difficulty)

    song_name = struct_song['name'].replace(' ', '_').replace(
        "'", '').replace(',', '').replace('(', '').replace(
        ')', '').replace('.', '').replace('?', '').replace(
        '!', '').replace('&', '').replace('-', '_').lower()

    write_to_file(struct_song, os.path.join(
        output_path, f'{song_name}_{sampling_rate}.h'), song_name)


def bulk_parse_folder(input_folder_path, output_folder_path, difficulty, sampling_rate):
    """
    Parses all .chart files in the specified folder.
    """
    chorus_charts = os.listdir(input_folder_path)

    for chart in chorus_charts:
        print(f"Processing {chart}...")
        input_file = os.path.join(input_folder_path, chart, 'notes.chart')
        for rate in SAMPLING_RATE:
            parse_chart(input_file, output_folder_path, difficulty, rate)


if __name__ == "__main__":
    # Create the argument parser
    parser = argparse.ArgumentParser(
        description='Parse .chart files for ArduinoHero.')

    # Add arguments
    parser.add_argument('-s', '--single', action='store_true',
                        help='Parse a single file (instead of bulk folder)', default=(not BULK))
    parser.add_argument('-i', '--input', type=str,
                        help='Input .chart file or folder path', default=INPUT_FOLDER_PATH)
    parser.add_argument('-o', '--output', type=str,
                        help='Output folder path to save the h file(s)', default=OUTPUT_FOLDER_PATH)
    parser.add_argument('-d', '--difficulty', type=str,
                        help='Difficulty level of beat map to take from chart', default=DIFFICULTY_TO_PARSE)
    parser.add_argument('-r', '--sampling_rate', type=int,
                        help='Sampling rate (1 = quarter note, 2 = eighth note, 4 = sixteenth note, etc.)',
                        default=SAMPLING_RATE)

    # Parse the command line arguments
    args = parser.parse_args()

    # Run the script with the specified arguments
    if args.single:
        parse_chart(args.input, args.output,
                    args.difficulty, args.sampling_rate)
    else:
        bulk_parse_folder(args.input, args.output,
                          args.difficulty, args.sampling_rate)
