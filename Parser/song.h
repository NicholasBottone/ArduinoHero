#ifndef PARSER
  #define PARSER

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

    // Each float represents a bmp change during the song
    float *bpm_values;
    int *bpm_change_indexes;
    int bpm_values_length;

    // Each byte represents a beat
    // 00000000 = no note
    // 00011111 = 5 fret note
    byte *beats;
    int beats_length;
  };

#endif
