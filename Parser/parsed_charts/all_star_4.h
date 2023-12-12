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
  /* sampling_rate */ 4,
  /* bpm_values */ (float[]) {107.0, 122.0, 103.94, 26.0, 103.85, 104.2, 103.8, 103.9, 105.1, 103.95, 104.1, 103.9, 103.95, 104.15, 103.95, 103.95, 98.5, 90.5},
  /* bpm_change_indexes */ (int[]) {0, 0, 1, 16, 16, 24, 32, 40, 47, 48, 56, 64, 71, 79, 87, 95, 98, 98},
  /* bpm_values_length */ 18,
  /* beats */ (byte[]) {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 24, 0, 24, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 24, 0, 24, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 24, 0, 24, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 6, 0, 0, 0, 14, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 24, 0, 24, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 24, 0, 24, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 24, 0, 24, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 24, 0, 24, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 24, 0, 24, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 6, 0, 1, 0, 2, 0, 5, 0, 5, 0, 5, 5, 5, 5, 10, 0, 10, 0, 32, 32, 32, 32, 28, 0, 28, 0, 28, 28, 28, 28, 10, 0, 10, 0, 32, 32, 32, 32, 5, 0, 5, 0, 5, 5, 5, 5, 10, 0, 10, 0, 32, 32, 32, 32, 28, 0, 28, 0, 28, 28, 28, 28, 10, 0, 10, 0, 32, 32, 32, 32, 5, 0, 5, 0, 5, 5, 5, 5, 10, 0, 10, 0, 32, 32, 32, 32, 28, 0, 28, 0, 28, 28, 28, 28, 10, 0, 10, 0, 32, 32, 32, 32, 5, 0, 5, 0, 5, 5, 5, 5, 3, 0, 3, 0, 3, 3, 3, 3, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 24, 0, 24, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 24, 0, 24, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 24, 0, 24, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 24, 0, 24, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 6, 0, 1, 0, 2, 0, 5, 0, 5, 0, 5, 5, 5, 5, 10, 0, 10, 0, 32, 32, 32, 32, 28, 0, 28, 0, 28, 28, 28, 28, 10, 0, 10, 0, 32, 32, 32, 32, 5, 0, 5, 0, 5, 5, 5, 5, 10, 0, 10, 0, 32, 32, 32, 32, 28, 0, 28, 0, 28, 28, 28, 28, 10, 0, 10, 0, 32, 32, 32, 32, 5, 0, 5, 0, 5, 5, 5, 5, 10, 0, 10, 0, 32, 32, 32, 32, 28, 0, 28, 0, 28, 28, 28, 28, 10, 0, 10, 0, 32, 32, 32, 32, 5, 0, 5, 0, 5, 5, 5, 5, 3, 0, 3, 0, 3, 3, 3, 3, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 8, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 8, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 8, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 2, 0, 5, 0, 5, 0, 5, 5, 5, 5, 10, 0, 10, 0, 32, 32, 32, 32, 28, 0, 28, 0, 28, 28, 28, 28, 10, 0, 10, 0, 32, 32, 32, 32, 5, 0, 5, 0, 5, 5, 5, 5, 10, 0, 10, 0, 32, 32, 32, 32, 28, 0, 28, 0, 28, 28, 28, 28, 10, 0, 10, 0, 32, 32, 32, 32, 5, 0, 5, 0, 5, 5, 5, 5, 10, 0, 10, 0, 32, 32, 32, 32, 28, 0, 28, 0, 28, 28, 28, 28, 10, 0, 10, 0, 32, 32, 32, 32, 5, 0, 5, 0, 5, 5, 5, 5, 3, 0, 3, 0, 3, 3, 3, 3, 1, 0, 2, 0, 4, 0, 0, 0, 1, 0, 2, 0, 4, 0, 16, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 4, 0, 8, 0, 1, 0, 2, 0, 4, 0, 0, 0, 1, 0, 2, 0, 4, 0, 16, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 4, 0, 8, 0, 1, 0, 2, 0, 4, 0, 0, 0, 1, 0, 2, 0, 4, 0, 16, 0, 6, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 4, 0, 8, 0, 1, 0, 2, 0, 4, 0, 0, 0, 1, 0, 2, 0, 4, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0, 16, 0, 8, 0, 2, 0, 8, 0, 16, 0, 8, 0, 4, 0, 8, 0, 16, 0, 8, 0, 2, 0, 8, 0, 16, 0, 8, 0, 1, 0, 8, 0, 16, 0, 8, 0, 2, 0, 8, 0, 16, 0, 8, 0, 4, 0, 8, 0, 16, 0, 8, 0, 2, 0, 8, 0, 16, 0, 8, 0, 1, 0, 8, 0, 16, 0, 8, 0, 2, 0, 8, 0, 16, 0, 8, 0, 4, 0, 8, 0, 16, 0, 8, 0, 2, 0, 8, 0, 20, 0, 8, 0, 1, 0, 8, 0, 16, 0, 8, 0, 2, 0, 8, 0, 16, 0, 8, 0, 4, 0, 8, 0, 16, 0, 8, 0, 2, 0, 8, 0, 1, 0, 2, 0, 5, 0, 5, 0, 5, 5, 5, 5, 10, 0, 10, 0, 32, 32, 32, 32, 28, 0, 28, 0, 28, 28, 28, 28, 10, 0, 10, 0, 32, 32, 32, 32, 5, 0, 5, 0, 5, 5, 5, 5, 10, 0, 10, 0, 32, 32, 32, 32, 28, 0, 28, 0, 28, 28, 28, 28, 10, 0, 10, 0, 32, 32, 32, 32, 5, 0, 5, 0, 5, 5, 5, 5, 10, 0, 10, 0, 32, 32, 32, 32, 28, 0, 28, 0, 28, 28, 28, 28, 10, 0, 10, 0, 32, 32, 32, 32, 5, 0, 5, 0, 5, 5, 5, 5, 10, 0, 10, 0, 32, 32, 32, 32, 28, 0, 28, 0, 28, 28, 28, 28, 10, 0, 10, 0, 32, 32, 32, 32, 5, 0, 5, 0, 5, 5, 5, 5, 10, 0, 10, 0, 32, 32, 32, 32, 28, 0, 28, 0, 28, 28, 28, 28, 10, 0, 10, 0, 32, 32, 32, 32, 5, 0, 5, 0, 5, 5, 5, 5, 3, 0, 3, 0, 3, 3, 3, 3, 13},
  /* beats_length */ 1565,
};
