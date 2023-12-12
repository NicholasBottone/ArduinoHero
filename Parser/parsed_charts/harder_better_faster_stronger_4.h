#include "song.h"

Song harder_better_faster_stronger = {
  /* name */ "Harder, Better, Faster, Stronger",
  /* artist */ "Daft Punk",
  /* charter */ "bdawg712",
  /* album */ "Discovery",
  /* year */ 2001,
  /* genre */ "Dance",
  /* filename */ "harderbe.ogg",
  /* resolution */ 192,
  /* sampling_rate */ 4,
  /* bpm_values */ (float[]) {105.933, 123.45},
  /* bpm_change_indexes */ (int[]) {0, 3},
  /* bpm_values_length */ 2,
  /* beats */ (byte[]) {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 10, 0, 0, 1, 0, 0, 10, 0, 10, 0, 0, 1, 0, 0, 10, 0, 10, 0, 0, 1, 0, 0, 10, 0, 10, 0, 0, 1, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 0, 0, 14, 0, 10, 0, 0, 1, 0, 0, 10, 0, 10, 0, 0, 1, 0, 0, 10, 0, 10, 0, 0, 1, 0, 0, 10, 0, 10, 0, 0, 1, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 0, 0, 4, 8, 32, 0, 0, 0, 1, 0, 4, 0, 32, 0, 0, 0, 0, 2, 2, 0, 8, 0, 1, 0, 12, 0, 24, 0, 24, 8, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 16, 4, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 1, 0, 4, 0, 32, 0, 0, 0, 0, 2, 2, 0, 8, 0, 1, 0, 12, 0, 24, 0, 24, 8, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 16, 4, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 1, 0, 4, 0, 32, 0, 32, 0, 0, 2, 2, 0, 8, 0, 32, 32, 12, 0, 24, 0, 24, 8, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 16, 4, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 1, 0, 4, 0, 32, 0, 32, 0, 0, 2, 2, 0, 8, 0, 32, 32, 12, 0, 24, 0, 24, 8, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 16, 4, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 8, 0, 1, 0, 0, 0, 0, 0, 24, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 16, 4, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 1, 0, 4, 0, 32, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 12, 0, 24, 0, 0, 0, 0, 0, 32, 0, 0, 0, 32, 0, 0, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 16, 4, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 1, 0, 0, 0, 0, 0, 24, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 16, 4, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 12, 0, 24, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 16, 4, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 1, 0, 0, 0, 0, 0, 24, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 16, 4, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 1, 0, 4, 0, 32, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 12, 0, 24, 0, 0, 0, 0, 0, 32, 0, 0, 0, 32, 0, 0, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 0, 0, 4, 8, 32, 0, 0, 0, 1, 0, 4, 0, 32, 0, 32, 0, 0, 2, 2, 0, 8, 0, 0, 0, 12, 0, 24, 0, 24, 8, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 16, 4, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 1, 0, 4, 0, 32, 0, 32, 0, 0, 2, 2, 0, 8, 0, 0, 0, 12, 0, 24, 0, 24, 8, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 16, 4, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 5, 0, 4, 0, 32, 0, 0, 0, 0, 2, 2, 0, 8, 0, 0, 0, 12, 0, 24, 0, 24, 8, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 16, 4, 0, 16, 0, 0, 12, 2, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 12, 0, 0, 0, 12, 0, 0, 0, 12, 0, 0, 0, 12, 0, 0, 0, 32, 0, 0, 0, 32, 0, 0, 0, 32, 0, 0, 0, 32, 0, 0, 0, 2, 0, 8, 0, 2, 0, 8, 0, 2, 0, 8, 0, 2, 0, 8, 0, 1, 0, 16, 0, 1, 0, 16, 0, 1, 0, 16, 0, 1, 0, 16, 0, 12, 0, 0, 0, 12, 0, 0, 0, 12, 0, 0, 0, 12, 0, 0, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 12, 0, 2, 0, 12, 0, 2, 0, 12, 0, 2, 0, 12, 0, 1, 0, 20, 0, 1, 0, 20, 0, 1, 0, 20, 0, 1, 0, 20, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 32, 0, 0, 0, 32, 0, 0, 0, 32, 0, 0, 0, 32, 0, 0, 0, 6, 0, 12, 0, 2, 0, 12, 0, 2, 0, 12, 0, 2, 0, 12, 0, 1, 0, 20, 0, 1, 0, 20, 0, 1, 0, 20, 0, 1, 0, 20, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 12, 0, 24, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 16, 8, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 12, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 2, 12, 0, 0, 0, 0, 0, 12, 0, 0, 0, 12, 0, 0, 12, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 8, 4, 0, 8, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 12, 4, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 2, 12, 0, 0, 0, 0, 0, 12, 0, 12, 12, 0, 12, 12, 0, 12, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 16, 8, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 12, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 8, 4, 0, 8, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 12, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 2, 12, 0, 0, 0, 0, 0, 12, 0, 12, 12, 0, 12, 12, 0, 12, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 16, 8, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 12, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 8, 4, 0, 8, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 12, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 2, 12, 0, 0, 0, 0, 0, 12, 0, 12, 12, 0, 12, 12, 0, 12, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 16, 8, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 12, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 2, 12, 0, 0, 0, 0, 0, 12, 0, 0, 0, 12, 0, 0, 12, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 8, 4, 0, 8, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 12, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 2, 12, 0, 0, 0, 0, 0, 12},
  /* beats_length */ 1831,
};
