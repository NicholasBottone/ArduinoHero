#include "song.h"

Song song = {
  .name = "All Star",
  .artist = "Smash Mouth",
  .charter = "Daintii",
  .album = "Astro Lounge",
  .year = 1999,
  .genre = "rock",
  .filename = "allstar.ogg",
  .resolution = 192,
  .sampling_rate = 1,
  .bpm_values = (float[]) {107.0, 122.0, 103.94, 26.0, 103.85, 104.2, 103.8, 103.9, 105.1, 103.95, 104.1, 103.9, 103.95, 104.15, 103.95, 103.95, 98.5, 90.5},
  .bpm_change_indexes = (int[]) {0, 2, 3, 62, 63, 95, 127, 159, 187, 191, 223, 255, 283, 315, 347, 379, 390, 390},
  .bpm_values_length = 18,
  .beats = (byte[]) {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 14, 0, 12, 24, 24, 0, 18, 6, 0, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 3, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 3, 3, 13, 0, 0, 0, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 3, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 3, 3, 13, 0, 0, 0, 1, 0, 4, 4, 8, 0, 4, 0, 1, 0, 4, 4, 8, 0, 4, 0, 1, 0, 4, 4, 8, 0, 4, 0, 1, 0, 4, 4, 8, 0, 0, 7, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 3, 3, 3, 4, 3, 20, 3, 5, 3, 12, 3, 4, 3, 20, 3, 5, 3, 12, 3, 4, 3, 20, 7, 5, 3, 12, 3, 4, 3, 20, 0, 0, 0, 0, 9, 24, 10, 24, 12, 24, 10, 24, 9, 24, 10, 24, 12, 24, 10, 24, 9, 24, 10, 24, 12, 24, 10, 28, 9, 24, 10, 24, 12, 24, 10, 3, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 3, 3, 13},
  .beats_length = 392
};
