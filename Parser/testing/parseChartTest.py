import unittest
import pathlib
import sys
sys.path.append(str(pathlib.Path(__file__).parent.parent))

from parseChart import create_arduinohero_struct, process_bpm_changes, process_arudinohero_beats, parse_chart_file

# Read in from mock_song.chart
mock_song_path = pathlib.Path(__file__).parent / 'mock_song.chart'
with open(mock_song_path, 'r') as file:
    mock_chart_data = parse_chart_file(str(mock_song_path), "ExpertSingle", 4)

print("Parsed Chart Data Structure:", mock_chart_data)  

class TestCreateArduinoheroStruct(unittest.TestCase):
    def test_valid_song_info(self): 
        result = create_arduinohero_struct(mock_chart_data, 4, "ExpertSingle")
        # Check for presence of keys
        self.assertIn('name', result)
        self.assertIn('artist', result)
        self.assertIn('charter', result)
        self.assertIn('album', result)
        self.assertIn('year', result)
        self.assertIn('genre', result)
        self.assertIn('filename', result)
        self.assertIn('resolution', result)
        self.assertIn('sampling_rate', result)
        self.assertIn('beats', result)
        self.assertIn('beats_length', result)
        self.assertIn('bpm_values', result)
        self.assertIn('bpm_values_length', result)
        self.assertIn('bpm_change_indexes', result)

        # Check for correctness of values
        self.assertEqual(result['name'], "Mock Song")
        self.assertEqual(result['artist'], "Test Artist")
        self.assertEqual(result['charter'], "Test Charter")
        self.assertEqual(result['album'], "Test Album")
        self.assertEqual(result['year'], 2023)
        self.assertEqual(result['genre'], "Test")
        self.assertEqual(result['filename'], "mock_song.ogg")
        self.assertEqual(result['resolution'], 192)
        self.assertEqual(result['sampling_rate'], 4)
        self.assertEqual(result['beats_length'], 99)
        self.assertEqual(result['bpm_values'], [90.0, 180.0])
        self.assertEqual(result['bpm_values_length'], 2)
        self.assertEqual(result['bpm_change_indexes'], [0, 4])

class TestProcessBpmChanges(unittest.TestCase):
    def test_valid_bpm_changes(self):
        bpm_values, bpm_change_indexes = process_bpm_changes(mock_chart_data, 192, 4)
        self.assertEqual(bpm_values, [90.0, 180.0])
        self.assertEqual(bpm_change_indexes, [0, 4])  # Adjusting index based on the resolution and sample rate

    def test_no_bpm_changes(self):
        no_bpm_data = mock_chart_data.copy()
        no_bpm_data['SyncTrack'] = []
        bpm_values, bpm_change_indexes = process_bpm_changes(no_bpm_data, 192, 4)
        self.assertEqual(bpm_values, [])
        self.assertEqual(bpm_change_indexes, [])


if __name__ == '__main__':
    unittest.main()
