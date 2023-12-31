#include "song.h"

Song all_i_want_for_christmas_is_you = {
  /* name */ "All I Want For Christmas Is You",
  /* artist */ "Mariah Carey",
  /* charter */ "NunoVH",
  /* album */ "Merry Christmas",
  /* year */ 1994,
  /* genre */ "Holiday",
  /* filename */ "alliwant.ogg",
  /* resolution */ 192,
  /* sampling_rate */ 1,
  /* bpm_values */ (float[]) {139.592, 140.0, 125.342, 88.0, 109.748, 130.0, 119.402, 116.0, 110.232, 112.0, 124.644, 108.41, 107.516, 148.305, 150.313, 150.0, 150.0, 150.085, 150.0, 150.072, 150.0},
  /* bpm_change_indexes */ (int[]) {0, 8, 12, 16, 24, 32, 40, 48, 56, 64, 68, 76, 81, 97, 109, 145, 237, 345, 389, 485, 537},
  /* bpm_values_length */ 21,
  /* beats */ (byte[]) {1, 2, 4, 8, 20, 8, 4, 2, 5, 2, 4, 8, 6, 0, 28, 24, 8, 0, 3, 12, 16, 15, 6, 0, 0, 24, 8, 6, 8, 31, 7, 0, 0, 3, 4, 8, 16, 15, 3, 0, 0, 24, 15, 14, 30, 3, 1, 0, 12, 16, 6, 10, 4, 3, 1, 0, 16, 30, 4, 2, 4, 3, 0, 0, 0, 31, 20, 0, 24, 8, 0, 0, 7, 31, 6, 0, 16, 28, 6, 0, 4, 3, 10, 0, 31, 0, 8, 0, 28, 30, 15, 7, 0, 7, 0, 12, 12, 7, 7, 7, 7, 11, 11, 11, 11, 13, 13, 13, 13, 8, 8, 8, 31, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 8, 16, 4, 10, 4, 6, 6, 0, 12, 16, 4, 10, 4, 6, 6, 0, 1, 2, 20, 24, 24, 8, 0, 0, 14, 31, 27, 23, 15, 29, 0, 30, 31, 0, 0, 30, 12, 3, 0, 0, 8, 0, 16, 8, 8, 8, 8, 31, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 8, 16, 4, 10, 4, 6, 6, 0, 16, 12, 4, 6, 4, 6, 6, 0, 1, 2, 20, 24, 24, 8, 1, 30, 14, 31, 27, 23, 15, 29, 0, 30, 31, 0, 0, 30, 12, 3, 0, 0, 15, 30, 31, 28, 31, 31, 15, 28, 31, 3, 12, 24, 8, 6, 6, 2, 1, 6, 8, 31, 30, 14, 15, 30, 0, 0, 6, 8, 16, 12, 12, 4, 8, 24, 4, 31, 25, 31, 30, 15, 30, 1, 6, 12, 4, 4, 28, 28, 31, 1, 6, 8, 24, 6, 6, 0, 12, 8, 8, 8, 8, 8, 8, 8, 16, 12, 12, 24, 8, 4, 2, 15, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 12, 16, 4, 10, 4, 6, 6, 0, 16, 12, 4, 6, 4, 6, 6, 0, 16, 2, 18, 24, 24, 8, 1, 30, 14, 31, 27, 23, 15, 29, 0, 24, 15, 15, 14, 7, 15, 31, 30, 0, 0, 14, 12, 12, 12, 12, 12, 12, 12, 12, 12, 15, 15, 3, 3, 6, 15, 28, 14, 14, 14, 14, 14, 14, 14, 14, 14, 31, 14, 14, 14, 16, 4, 24, 12, 12, 14, 28, 6, 3, 3, 24, 12, 12, 6, 6, 5, 3, 0, 16, 8, 12, 16, 8, 8, 8, 8, 8, 8, 10, 4, 2, 3, 1, 29, 23, 23, 27, 29, 23, 0, 27, 29, 0, 30, 29, 29, 15, 0, 0, 29, 23, 23, 27, 29, 23, 0, 27, 29, 0, 30, 29, 29, 15},
  /* beats_length */ 567,
};
