import sys
import os
import logging

# https://docs.google.com/document/d/1v2v0U-9HQ5qHeccpExDOLJ5CMPZZ3QytPmAG5WF0Kzs/mobilebasic
# (tickEnd - tickStart) / resolution * 60.0 (seconds per minute) / bpm

"""
Global Variables:
    INPUT_FILE: Path to the input .chart file, typically located in the same directory as this script.
    OUTPUT_FILE: Path for the output structured file, which will be in the format of a .ino header file.
    DIFFICULTY_TO_PARSE: 
        .chart files contain note information for multiple difficulties, this variable
        selects which difficulty to parse since we only output a single version of the song
        to be used by the ArduinoHero game.
    SAMPLING_RATE: 
        Notes sampled from .chart file @ Resolution * Sampling Rate.
        Basically, this is sample every quarter note (SAMPLING_RATE == 1), eighth note (SAMPLING_RATE == .5), etc.
"""
INPUT_FILE = os.path.join(os.path.dirname(__file__), 'allstar_notes.chart')
OUTPUT_FILE = os.path.join(os.path.dirname(__file__), 'allstar_chart.h')
DIFFICULTY_TO_PARSE = 'ExpertSingle'
SAMPLING_RATE = 1 # 1 = quarter note, .5 = eighth note, .25 = sixteenth note, etc. 

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
  
  // The BPMs in order that they appear in the song
  'bpm_values': [], // [155, 160, ...] (value to change the bpm to)

  // The index in beats[] that the bpm changes occurs at (parallel array to bpm_values)
  'bpm_change_indexes': [], # [0, 815]
};
"""


def parseChart():
    """Parses the chart file and returns a list of strings that make up the file."""
    file = [
        '#include "song.h"\n',
        '\n',
        'Song song = {\n',
    ]
    resolution = 192
    with open(FILE_TO_PARSE, 'r') as chart:
        current_section = None
        for line in chart:
            line = line.strip()
            if line.startswith('['):
                current_section = line[1:-1]
                song_data[current_section] = []
            elif '=' in line and current_section:
                key, value = line.split('=', 1)
                song_data[current_section].append((key.strip(), value.strip().strip('"')))
            elif current_section == DIFFICULTY_TO_PARSE and '=' in line:
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
            bpm_str = event.split(' ')[1]  # Splitting the string and getting the BPM part
            tick = int(tick)
            bpm = float(bpm_str) / 1000  # Converting to actual BPM value

            # Calculate the index of the beat (in the beats[] list we will make next) of the BPM change
            index = tick / (resolution * sample_rate)

            # Log a warning if the index is not an integer and round it
            if not index.is_integer():
                logging.warning(f"BPM change index is not an integer, rounding: {index} to {round(index)}")
                index = round(index)


            bpm_values.append(bpm)
            bpm_change_indexes.append(int(index))  # Convert to int for whole number

    return bpm_values, bpm_change_indexes


def process_arudinohero_beats(song_data, resolution, sampling_rate):
    beats = []
    # Mapping of note types to their bit positions
    note_bit_positions = {
        '0': 0b000001,  # Green
        '1': 0b000010,  # Red
        '2': 0b000100,  # Yellow
        '3': 0b001000,  # Blue
        '4': 0b010000,  # Orange
        '7': 0b1000000,  # Open note
    }

    # Adjusting ticks_per_sample based on sampling_rate
    ticks_per_sample = resolution / sampling_rate
    current_sample_ticks = 0
    current_sample_byte = 0b000000

    for beat in song_data[DIFFICULTY_TO_PARSE]:
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


def create_arduinohero_struct(song_data):
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
    resolution = int(song_info_dict.get('Resolution', '192'))  # Using a default value if not found

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
        'sampling_rate': SAMPLING_RATE, 

        'beats': [], # [0b00000001, 0b00000010, ...]
                     # Each byte represents a beat.
                     # Each beat is not necessarily a quarter note, 
                     # it depends on the sampling rate & resolution.
                     # (00000000 = no note (rest), 00011111 = 5 fret note, etc.)

        'bpm_values': [], # [155, 160] 
                          # (The BPMs in order that they appear in the song)
        'bpm_change_indexes': [], # [0, 815, ...]
                                  # The index in beats[] that the bpm changes occurs at 
                                  # (parallel array to bpm_values)
                    
    }

    struct_song['bpm_values'], struct_song['bpm_change_indexes'] = process_bpm_changes(song_data, resolution, SAMPLING_RATE)

    # Process and generate the necessary information for an ArudinoHero beat chart
    struct_song['beats'] =  process_arudinohero_beats(song_data, resolution, SAMPLING_RATE)

    return struct_song

def write_to_file(struct_song, output_file):
    """
    Writes the converted song data into a .h file in struct format.
    """
    with open(output_file, 'w') as file:
        file.write('struct Song {\n')
        for key, value in struct_song.items():
            if isinstance(value, str):
                file.write(f'  char *{key} = "{value}";\n')
            elif isinstance(value, int):
                file.write(f'  int {key} = {value};\n')
            elif isinstance(value, list):
                if key == 'beats':
                    # Convert each integer in the list to a string
                    beats_str = ', '.join(str(beat) for beat in value)
                    file.write(f'  byte beats[] = {{{beats_str}}};\n')
                elif key == 'bpm_values':
                    bpm_values_str = ', '.join(str(bpm) for bpm in value)
                    file.write(f'  float bpm_values[] = {{{bpm_values_str}}};\n')
                elif key == 'bpm_change_indexes':
                    bpm_indexes_str = ', '.join(str(index) for index in value)
                    file.write(f'  int bpm_change_indexes[] = {{{bpm_indexes_str}}};\n')
        file.write('};\n')



def main():
    song_data = parse_chart_file(INPUT_FILE)
    struct_song = create_arduinohero_struct(song_data)
    write_to_file(struct_song, OUTPUT_FILE)

if __name__ == "__main__":
    main()