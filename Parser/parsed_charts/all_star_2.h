#include "song.h"

Song all_star = {
  /* name */ "All Star",
  /* artist */ "Smash Mouth",
  /* charter */ "Daintii",
  /* album */ "Astro Lounge",
  /* year */ 1999,
  /* genre */ "rock",
  /* filename */ "allstars.mp3",
  /* resolution */ 192,
  /* sampling_rate */ 2,
  /* bpm_values */ (float[]) {107.0, 122.0, 103.94, 26.0, 103.85, 104.2, 103.8, 103.9, 105.1, 103.95, 104.1, 103.9, 103.95, 104.15, 103.95, 103.95, 98.5, 90.5},
  /* bpm_change_indexes */ (int[]) {0, 1, 2, 31, 32, 48, 64, 80, 94, 96, 112, 128, 142, 158, 174, 190, 195, 195},
  /* bpm_values_length */ 18,
  /* beats */ (byte[]) {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 24, 24, 0, 0, 0, 18, 0, 0, 6, 0, 6, 0, 0, 12, 0, 0, 24, 24, 0, 0, 0, 18, 0, 0, 6, 0, 6, 0, 0, 12, 0, 0, 24, 24, 0, 0, 0, 18, 0, 0, 6, 0, 14, 0, 0, 12, 0, 0, 24, 24, 0, 0, 0, 18, 0, 0, 6, 0, 0, 0, 0, 12, 0, 0, 24, 24, 0, 0, 0, 18, 0, 0, 6, 0, 6, 0, 0, 12, 0, 0, 24, 24, 0, 0, 0, 18, 0, 0, 6, 0, 6, 0, 0, 12, 0, 0, 24, 24, 0, 0, 0, 18, 0, 0, 6, 0, 6, 0, 0, 12, 0, 0, 24, 24, 0, 0, 0, 18, 0, 0, 6, 1, 2, 5, 5, 5, 5, 10, 10, 32, 32, 28, 28, 28, 28, 10, 10, 32, 32, 5, 5, 5, 5, 10, 10, 32, 32, 28, 28, 28, 28, 10, 10, 32, 32, 5, 5, 5, 5, 10, 10, 32, 32, 28, 28, 28, 28, 10, 10, 32, 32, 5, 5, 5, 5, 3, 3, 3, 3, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 24, 24, 0, 0, 0, 18, 0, 0, 6, 0, 6, 0, 0, 12, 0, 0, 24, 24, 0, 0, 0, 18, 0, 0, 6, 0, 6, 0, 0, 12, 0, 0, 24, 24, 0, 0, 0, 18, 0, 0, 6, 0, 6, 0, 0, 12, 0, 0, 24, 24, 0, 0, 0, 18, 0, 0, 6, 1, 2, 5, 5, 5, 5, 10, 10, 32, 32, 28, 28, 28, 28, 10, 10, 32, 32, 5, 5, 5, 5, 10, 10, 32, 32, 28, 28, 28, 28, 10, 10, 32, 32, 5, 5, 5, 5, 10, 10, 32, 32, 28, 28, 28, 28, 10, 10, 32, 32, 5, 5, 5, 5, 3, 3, 3, 3, 13, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 4, 8, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 4, 8, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 4, 8, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 4, 8, 0, 0, 0, 0, 0, 5, 2, 5, 5, 5, 5, 10, 10, 32, 32, 28, 28, 28, 28, 10, 10, 32, 32, 5, 5, 5, 5, 10, 10, 32, 32, 28, 28, 28, 28, 10, 10, 32, 32, 5, 5, 5, 5, 10, 10, 32, 32, 28, 28, 28, 28, 10, 10, 32, 32, 5, 5, 5, 5, 3, 3, 3, 3, 1, 2, 4, 0, 1, 2, 4, 16, 2, 1, 4, 1, 2, 1, 4, 8, 1, 2, 4, 0, 1, 2, 4, 16, 2, 1, 4, 1, 2, 1, 4, 8, 1, 2, 4, 0, 1, 2, 4, 16, 6, 1, 4, 1, 2, 1, 4, 8, 1, 2, 4, 0, 1, 2, 4, 16, 0, 0, 0, 0, 0, 0, 0, 0, 1, 8, 16, 8, 2, 8, 16, 8, 4, 8, 16, 8, 2, 8, 16, 8, 1, 8, 16, 8, 2, 8, 16, 8, 4, 8, 16, 8, 2, 8, 16, 8, 1, 8, 16, 8, 2, 8, 16, 8, 4, 8, 16, 8, 2, 8, 20, 8, 1, 8, 16, 8, 2, 8, 16, 8, 4, 8, 16, 8, 2, 8, 1, 2, 5, 5, 5, 5, 10, 10, 32, 32, 28, 28, 28, 28, 10, 10, 32, 32, 5, 5, 5, 5, 10, 10, 32, 32, 28, 28, 28, 28, 10, 10, 32, 32, 5, 5, 5, 5, 10, 10, 32, 32, 28, 28, 28, 28, 10, 10, 32, 32, 5, 5, 5, 5, 10, 10, 32, 32, 28, 28, 28, 28, 10, 10, 32, 32, 5, 5, 5, 5, 10, 10, 32, 32, 28, 28, 28, 28, 10, 10, 32, 32, 5, 5, 5, 5, 3, 3, 3, 3, 13},
  /* beats_length */ 783,
};
