#include "song.h"

#ifndef SONGS
  #define SONGS

    Song all_star = {
    /* name */ "All Star",
    /* artist */ "Smash Mouth",
    /* charter */ "Daintii",
    /* album */ "Astro Lounge",
    /* year */ 1999,
    /* genre */ "rock",
    /* filename */ "song.ogg",
    /* resolution */ 192,
    /* sampling_rate */ 1,
    /* bpm_values */ (float[]) {107.0, 122.0, 103.94, 26.0, 103.85, 104.2, 103.8, 103.9, 105.1, 103.95, 104.1, 103.9, 103.95, 104.15, 103.95, 103.95, 98.5, 90.5},
    /* bpm_change_indexes */ (int[]) {0, 2, 3, 62, 63, 95, 127, 159, 187, 191, 223, 255, 283, 315, 347, 379, 390, 390},
    /* bpm_values_length */ 18,
    /* beats */ (byte[]) {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 14, 0, 12, 24, 24, 0, 18, 6, 0, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 3, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 3, 3, 13, 0, 0, 0, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 6, 0, 12, 24, 24, 0, 18, 6, 3, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 3, 3, 13, 0, 0, 0, 1, 0, 4, 4, 8, 0, 4, 0, 1, 0, 4, 4, 8, 0, 4, 0, 1, 0, 4, 4, 8, 0, 4, 0, 1, 0, 4, 4, 8, 0, 0, 7, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 3, 3, 3, 4, 3, 20, 3, 5, 3, 12, 3, 4, 3, 20, 3, 5, 3, 12, 3, 4, 3, 20, 7, 5, 3, 12, 3, 4, 3, 20, 0, 0, 0, 0, 9, 24, 10, 24, 12, 24, 10, 24, 9, 24, 10, 24, 12, 24, 10, 24, 9, 24, 10, 24, 12, 24, 10, 28, 9, 24, 10, 24, 12, 24, 10, 3, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 10, 64, 28, 28, 10, 64, 5, 5, 3, 3, 13},
    /* beats_length */ 392,
  };
  Song dream_on = {
  /* name */ "Dream On",
  /* artist */ "Aerosmith",
  /* charter */ "thardwardy",
  /* album */ "Aerosmith",
  /* year */ 1973,
  /* genre */ "Rock",
  /* filename */ "song.ogg",
  /* resolution */ 192,
  /* sampling_rate */ 1,
  /* bpm_values */ (float[]) {77.511, 78.139, 78.515, 78.779, 77.274, 77.835, 79.55, 77.486, 79.304, 77.797, 79.052, 79.12, 78.005, 75.669, 77.111, 76.986, 75.608, 76.061, 76.569, 76.58, 76.078, 76.444, 76.546, 77.301, 77.721, 78.989, 79.949, 79.636, 77.72, 77.36, 78.956, 76.713, 76.195, 76.689, 78.308, 77.114, 77.657, 77.333, 78.237, 76.364, 77.534, 78.005, 78.98, 81.429, 80.96, 77.941, 77.786, 78.278, 78.433, 80.288, 79.578, 77.925, 77.689, 77.975, 78.826, 79.715, 81.177, 79.737, 78.906, 78.385, 80.467, 79.72, 80.832, 81.396, 81.726, 82.718, 81.86, 81.894, 82.434, 81.81, 82.481, 82.397, 79.782, 79.844, 80.883, 81.529, 82.426, 82.656, 81.843, 81.06, 82.446, 81.983, 80.745, 81.278, 79.77, 79.973, 78.915},
  /* bpm_change_indexes */ (int[]) {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140, 144, 148, 152, 156, 160, 164, 168, 172, 176, 180, 184, 188, 192, 196, 200, 204, 208, 212, 216, 220, 224, 228, 232, 236, 240, 244, 248, 252, 256, 260, 264, 268, 272, 276, 280, 284, 288, 292, 296, 300, 304, 308, 312, 316, 320, 324, 328, 332, 336, 340, 344},
  /* bpm_values_length */ 87,
  /* beats */ (byte[]) {0, 0, 0, 0, 13, 13, 7, 7, 10, 11, 5, 5, 13, 13, 21, 21, 25, 25, 24, 0, 13, 13, 7, 7, 11, 11, 5, 5, 13, 13, 21, 21, 24, 24, 28, 20, 18, 18, 27, 9, 5, 5, 5, 5, 7, 12, 30, 24, 14, 7, 24, 0, 13, 12, 7, 7, 10, 11, 5, 5, 13, 13, 7, 7, 11, 11, 5, 5, 13, 13, 7, 7, 11, 74, 5, 5, 13, 13, 7, 7, 11, 11, 5, 5, 13, 13, 7, 7, 11, 11, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 30, 10, 15, 5, 13, 12, 28, 20, 30, 10, 15, 5, 13, 12, 12, 13, 13, 7, 7, 11, 11, 15, 30, 0, 0, 21, 21, 25, 25, 24, 0, 13, 12, 7, 7, 11, 11, 5, 5, 13, 13, 7, 7, 11, 11, 5, 5, 13, 13, 7, 7, 11, 11, 5, 5, 13, 13, 7, 7, 11, 11, 5, 5, 20, 30, 10, 15, 5, 13, 12, 12, 67, 64, 7, 1, 14, 2, 28, 4, 5, 5, 5, 5, 5, 5, 5, 7, 7, 15, 14, 14, 28, 14, 16, 0, 10, 2, 10, 2, 10, 6, 10, 0, 69, 7, 75, 11, 28, 14, 16, 0, 10, 2, 10, 3, 20, 30, 10, 15, 5, 13, 12, 12, 67, 64, 7, 1, 14, 2, 28, 4, 6, 6, 7, 14, 24, 30, 79, 28, 3, 3, 5, 5, 10, 10, 20, 20, 24, 24, 24, 24, 24, 6, 28, 3, 3, 3, 5, 5, 14, 10, 20, 20, 15, 6, 30, 28, 15, 6, 8, 16, 3, 3, 5, 5, 10, 10, 20, 20, 5, 5, 6, 6, 12, 12, 24, 24, 5, 5, 5, 5, 5, 5, 5, 5, 20, 30, 10, 15, 5, 13, 12, 28, 20, 30, 10, 15, 5, 13, 12, 28, 20, 30, 10, 15, 5, 13, 12, 12, 67, 64, 7, 1, 14, 2, 28, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4},
  /* beats_length */ 351,
};
#include "song.h"

Song dream_on_doublesample = {
  /* name */ "Dream On",
  /* artist */ "Aerosmith",
  /* charter */ "thardwardy",
  /* album */ "Aerosmith",
  /* year */ 1973,
  /* genre */ "Rock",
  /* filename */ "song.ogg",
  /* resolution */ 192,
  /* sampling_rate */ 2,
  /* bpm_values */ (float[]) {77.511, 78.139, 78.515, 78.779, 77.274, 77.835, 79.55, 77.486, 79.304, 77.797, 79.052, 79.12, 78.005, 75.669, 77.111, 76.986, 75.608, 76.061, 76.569, 76.58, 76.078, 76.444, 76.546, 77.301, 77.721, 78.989, 79.949, 79.636, 77.72, 77.36, 78.956, 76.713, 76.195, 76.689, 78.308, 77.114, 77.657, 77.333, 78.237, 76.364, 77.534, 78.005, 78.98, 81.429, 80.96, 77.941, 77.786, 78.278, 78.433, 80.288, 79.578, 77.925, 77.689, 77.975, 78.826, 79.715, 81.177, 79.737, 78.906, 78.385, 80.467, 79.72, 80.832, 81.396, 81.726, 82.718, 81.86, 81.894, 82.434, 81.81, 82.481, 82.397, 79.782, 79.844, 80.883, 81.529, 82.426, 82.656, 81.843, 81.06, 82.446, 81.983, 80.745, 81.278, 79.77, 79.973, 78.915},
  /* bpm_change_indexes */ (int[]) {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100, 102, 104, 106, 108, 110, 112, 114, 116, 118, 120, 122, 124, 126, 128, 130, 132, 134, 136, 138, 140, 142, 144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 166, 168, 170, 172},
  /* bpm_values_length */ 87,
  /* beats */ (byte[]) {0, 0, 0, 0, 0, 0, 0, 0, 12, 1, 12, 1, 6, 1, 6, 1, 10, 0, 10, 1, 5, 1, 5, 1, 12, 1, 12, 1, 20, 1, 20, 1, 24, 1, 24, 1, 24, 0, 0, 0, 12, 1, 12, 1, 6, 1, 6, 1, 10, 1, 10, 1, 5, 1, 5, 1, 12, 1, 12, 1, 20, 1, 20, 1, 24, 0, 24, 0, 20, 12, 0, 20, 18, 0, 18, 0, 18, 9, 0, 9, 4, 1, 4, 1, 4, 1, 4, 1, 6, 3, 12, 12, 12, 18, 24, 24, 12, 6, 3, 7, 24, 0, 0, 0, 12, 1, 12, 0, 6, 1, 6, 1, 10, 0, 10, 1, 5, 1, 5, 1, 12, 1, 12, 1, 6, 1, 6, 1, 10, 1, 10, 1, 5, 1, 5, 1, 12, 1, 12, 1, 6, 1, 6, 1, 10, 1, 10, 64, 5, 1, 5, 1, 12, 1, 12, 1, 6, 1, 6, 1, 10, 1, 10, 1, 5, 1, 5, 1, 12, 1, 12, 1, 6, 1, 6, 1, 10, 1, 10, 1, 5, 1, 5, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 20, 0, 0, 30, 10, 0, 0, 15, 5, 0, 0, 13, 12, 0, 0, 28, 20, 0, 0, 30, 10, 0, 0, 15, 5, 0, 0, 13, 12, 0, 0, 12, 12, 1, 12, 1, 6, 1, 6, 1, 10, 1, 10, 1, 3, 12, 6, 24, 0, 0, 0, 0, 20, 1, 20, 1, 24, 1, 24, 1, 24, 0, 0, 0, 12, 1, 12, 0, 6, 1, 6, 1, 10, 1, 10, 1, 5, 1, 5, 1, 12, 1, 12, 1, 6, 1, 6, 1, 10, 1, 10, 1, 5, 1, 5, 1, 12, 1, 12, 1, 6, 1, 6, 1, 10, 1, 10, 1, 5, 1, 5, 1, 12, 1, 12, 1, 6, 1, 6, 1, 10, 1, 10, 1, 5, 1, 5, 1, 20, 0, 0, 30, 10, 0, 0, 15, 5, 0, 0, 13, 12, 0, 0, 12, 3, 64, 64, 0, 6, 1, 1, 0, 12, 2, 2, 0, 24, 4, 4, 0, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 6, 1, 5, 3, 6, 9, 6, 12, 10, 6, 24, 20, 12, 14, 16, 0, 0, 0, 8, 10, 2, 0, 10, 2, 2, 2, 2, 10, 6, 0, 10, 0, 0, 0, 5, 64, 6, 5, 3, 72, 10, 3, 24, 20, 12, 14, 16, 0, 0, 0, 8, 10, 2, 0, 10, 2, 0, 3, 20, 0, 0, 30, 10, 0, 0, 15, 5, 0, 0, 13, 12, 0, 0, 12, 3, 64, 64, 0, 6, 1, 1, 0, 12, 2, 2, 0, 24, 4, 4, 0, 6, 0, 6, 0, 6, 1, 12, 6, 24, 24, 24, 6, 65, 14, 12, 16, 3, 0, 0, 3, 5, 0, 0, 5, 10, 0, 0, 10, 20, 0, 0, 20, 24, 0, 24, 0, 24, 0, 24, 0, 24, 8, 4, 6, 16, 12, 3, 1, 3, 0, 0, 3, 5, 0, 0, 5, 14, 0, 0, 10, 20, 0, 0, 20, 12, 3, 6, 2, 24, 6, 28, 24, 12, 3, 6, 6, 8, 8, 16, 16, 3, 0, 0, 3, 5, 0, 0, 5, 10, 0, 0, 10, 20, 0, 0, 20, 5, 0, 0, 5, 6, 0, 0, 6, 12, 0, 0, 12, 24, 0, 0, 24, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 20, 0, 0, 30, 10, 0, 0, 15, 5, 0, 0, 13, 12, 0, 0, 28, 20, 0, 0, 30, 10, 0, 0, 15, 5, 0, 0, 13, 12, 0, 0, 28, 20, 0, 0, 30, 10, 0, 0, 15, 5, 0, 0, 13, 12, 0, 0, 12, 3, 64, 64, 0, 6, 1, 1, 0, 12, 2, 2, 0, 24, 4, 4, 0, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4},
  /* beats_length */ 701,
};

Song test_song = {
    /* name */ "Test Song",
    /* artist */ "arduinoherohomies",
    /* charter */ "señor david",
    /* album */ "bdw vibes",
    /* year */ 2023,
    /* genre */ "!?",
    /* filename */ "song.ogg",
    /* resolution */ 192,
    /* sampling_rate */ 1,
    /* bpm_values */ (float[]) {150.0},
    /* bpm_change_indexes */ (int[]) {0},
    /* bpm_values_length */ 1,
    /* beats */ (byte[]) {0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000/*, 0b11111111*/},
    /* beats_length */ 10,
  };


  Song songList[] = {
    test_song,
      all_star,
      dream_on,
      dream_on_doublesample
  };


#endif
