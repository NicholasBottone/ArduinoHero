import sys
import os

FILE_TO_PARSE = os.path.join(os.path.dirname(__file__), 'notes.chart')
OUTPUT_FILE = os.path.join(os.path.dirname(__file__), 'chart.h')
DIFFICULTY = 'Easy'

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
  float tempo; // milliseconds per beat
  // Each byte represents a beat
  // 00000000 = no note
  // 00011111 = 5 fret note
  byte *beats;
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
                current_section = line[1:-2]
                continue
            if line.startswith('{'):
                continue
            if line.startswith('}'):
                current_section = None
                continue
            if current_section == 'Song':
                if line.startswith('Name'):
                    file.append(f'char *name = "{line[8:-1]}";\n')
                elif line.startswith('Artist'):
                    file.append(f'char *artist = "{line[10:-1]}";\n')
                elif line.startswith('Charter'):
                    file.append(f'char *charter = "{line[11:-1]}";\n')
                elif line.startswith('Album'):
                    file.append(f'char *album = "{line[9:-1]}";\n')
                elif line.startswith('Year'):
                    file.append(f'int year = {line[-5:-1]};\n')
                elif line.startswith('Genre'):
                    file.append(f'char *genre = "{line[9:-1]}";\n')
                elif line.startswith('MusicStream'):
                    file.append(f'char *filename = "{line[14:-1]}";\n')
                elif line.startswith('Resolution'):
                    resolution = int(line[13:])

            if current_section == f"{DIFFICULTY}Single":
                beat = int(line[:4])
                note = line[7]
                # file.append(f'byte TODO
                if note == 'N':
                    file.append(f'byte beats[{beat}] = 0;\n')  # TODO
                else:
                    # TODO: Convert note to byte
                    file.append(f'byte beats[{beat}] = {note};\n')

    file.append('};\n')

    return file


if __name__ == '__main__':
    # If no arguments are passed, print the chart
    # If argument is passed, save the chart to a file
    if len(sys.argv) == 1:
        print(parseChart())
    else:
        with open(sys.argv[1], 'w') as f:
            for note in parseChart():
                f.write(note)
