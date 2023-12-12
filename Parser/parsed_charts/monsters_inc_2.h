#include "song.h"

Song monsters_inc = {
  /* name */ "Monsters, Inc.",
  /* artist */ "Randy Newman",
  /* charter */ "JoeyD",
  /* album */ "Monsters, Inc (Original Motion Picture Soundtrack)",
  /* year */ 2001,
  /* genre */ "Jazz",
  /* filename */ "song.ogg",
  /* resolution */ 192,
  /* sampling_rate */ 2,
  /* bpm_values */ (float[]) {115.0, 220.0, 219.0, 150.0},
  /* bpm_change_indexes */ (int[]) {0, 2, 210, 214},
  /* bpm_values_length */ 4,
  /* beats */ (byte[]) {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 8, 16, 8, 4, 2, 0, 3, 4, 8, 16, 8, 4, 1, 0, 5, 6, 8, 4, 0, 8, 16, 1, 2, 4, 8, 2, 4, 1, 0, 0, 0, 0, 0, 0, 0, 4, 4, 8, 16, 2, 0, 2, 0, 0, 0, 16, 0, 0, 0, 0, 0, 4, 4, 8, 16, 1, 0, 0, 0, 0, 16, 4, 8, 4, 0, 0, 0, 0, 6, 4, 8, 16, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 16, 0, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 4, 8, 16, 2, 0, 2, 0, 0, 16, 8, 4, 8, 0, 0, 4, 0, 4, 8, 16, 1, 0, 0, 16, 0, 0, 0, 8, 4, 0, 0, 2, 1, 4, 16, 0, 0, 24, 12, 2, 1, 2, 4, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 6, 8, 16, 0, 0, 4, 4, 8, 16, 2, 0, 2, 0, 0, 0, 0, 24, 8, 0, 0, 0, 4, 4, 8, 16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 2, 0, 4, 8, 16, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 16, 1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 8, 16, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 8, 16, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 8, 16, 0, 0, 8, 4, 2, 1, 2, 4, 0, 0, 1, 4, 6, 8, 16, 8, 0, 1, 2, 1, 2, 4, 8, 16, 0, 0, 0, 0, 8, 4, 8, 0, 8, 4, 8, 16, 0, 0, 0, 0, 24, 2, 4, 0, 4, 2, 4, 8, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 2, 0, 0, 1, 2, 4, 0, 0, 0, 0, 0, 8, 16, 8, 4, 2, 0, 0, 0, 4, 8, 4, 2, 1, 0, 0, 0, 0, 0, 0, 0, 4, 4, 8, 16, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 4, 8, 16, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 4, 16, 0, 0, 24, 12, 2, 1, 2, 4, 0, 0, 0, 0, 2, 0, 4, 16, 0, 0, 24, 12, 2, 1, 2, 4, 0, 0, 0, 4, 2, 0, 4, 16, 0, 0, 24, 12, 2, 1, 2, 4, 0, 0, 2, 16, 0, 0, 8, 2, 4, 0, 16, 4, 8, 0, 4, 1, 2, 0, 4, 0, 4, 8, 16, 2, 4, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 16, 8, 4, 24, 4, 2, 1, 4, 8, 0, 2, 0, 8, 0, 1, 0, 0, 2, 1, 2, 4, 16, 24, 8, 4, 2, 1, 2, 6, 4, 8, 16, 0, 0, 12, 0, 8, 0, 0, 1, 6, 8, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 4, 1, 2, 8, 0, 0, 4, 2, 1, 4, 2, 1, 2, 8, 0, 0, 8, 0, 0, 0, 0, 0, 24, 0, 8, 4, 2, 4, 3, 4, 8, 4, 8, 16, 0, 4, 8, 24, 4, 8, 4, 1, 2, 0, 1, 16, 16, 8, 16, 8, 16, 4, 8, 2, 8, 4, 8, 4, 8, 3, 4, 2, 4, 2, 4, 2, 4, 0, 2, 1, 2, 4, 8, 0, 4, 2, 1, 1, 2, 4, 8, 16, 0, 0, 0, 0, 0, 8, 0, 16, 8, 2, 4, 1, 2, 8, 4, 8, 2, 1, 16, 8, 4, 2, 1, 0, 2, 4, 0, 0, 8, 0, 16, 0, 0, 4, 0, 0, 8, 16, 0, 0, 6, 0, 0, 0, 8, 0, 16, 0, 8, 4, 16, 0, 8, 4, 0, 0, 0, 0, 0, 2, 0, 0, 8, 0, 2, 0, 4, 0, 2, 0, 4, 1, 2, 4, 0, 2, 0, 1, 0, 8, 16, 8, 4, 2, 1, 16, 8, 4, 2, 4, 1, 0, 3, 4, 8, 0, 0, 12, 4, 2, 4, 16, 0, 8, 0, 6, 4, 1, 2, 16, 8, 2, 4, 8, 2, 4, 2, 1, 2, 8, 0, 0, 4, 0, 1, 3, 0, 1, 2, 4, 8, 2, 4, 8, 1, 16, 0, 8, 4, 8, 4, 24, 0, 20, 0, 4, 12, 2, 4, 13, 0, 0, 0, 0, 7, 0, 4, 0, 4, 8, 16, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 4, 8, 16, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 4, 16, 0, 0, 24, 12, 2, 1, 2, 4, 0, 0, 0, 0, 2, 0, 4, 16, 0, 0, 24, 12, 2, 1, 2, 4, 0, 0, 0, 0, 2, 0, 4, 16, 0, 0, 24, 12, 2, 1, 2, 4, 0, 0, 2, 0, 0, 0, 0, 0, 3, 20, 8, 0, 4, 2, 6, 0, 1, 0, 3, 8, 0, 0, 0, 24, 12, 24},
  /* beats_length */ 882,
};
