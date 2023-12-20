#include "song.h"

Song deja_vu = {
  /* name */ "deja vu",
  /* artist */ "Olivia Rodrigo",
  /* charter */ "itsevanpaik",
  /* album */ "SOUR",
  /* year */ 2021,
  /* genre */ "Pop",
  /* filename */ "dejavuol.ogg",
  /* resolution */ 192,
  /* sampling_rate */ 4,
  /* bpm_values */ (float[]) {120.0, 90.5, 91.0, 91.0, 91.0, 90.3, 90.5},
  /* bpm_change_indexes */ (int[]) {0, 1, 39, 43, 53, 59, 65},
  /* bpm_values_length */ 7,
  /* beats */ (byte[]) {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 20, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 20, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 8, 16, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 16, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 4, 8, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 2, 0, 0, 0, 0, 0, 2, 4, 8, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 8, 0, 4, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 4, 0, 16, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 4, 0, 16, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 4, 0, 16, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 16, 0, 8, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 8, 16, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 16, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 4, 8, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 8, 16, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 16, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 4, 8, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 8, 16, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 16, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 4, 8, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 8, 16, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 16, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 4, 8},
  /* beats_length */ 1273,
};