#ifndef SONG
  #define SONG

  struct Song {
    char *name;
    char *artist;
    char *charter;
    char *album;
    int year;
    char *genre;
    char *filename;
    int resolution;
    int sampling_rate;

    // The BPMs in order that they appear in the song
    float *bpm_values;
    // The index in beats[] that the bpm changes occurs at (parallel array to bpm_values)
    int *bpm_change_indexes;
    // Length of both the bpm_values and bpm-change_indexes arrays
    int bpm_values_length;

    // Each byte represents a beat
    // 00000000 = no note
    // 00011111 = 5 fret note
    byte *beats;
    int beats_length;
  };

#endif
