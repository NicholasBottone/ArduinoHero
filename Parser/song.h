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

    float tempo; // milliseconds per beat

    // Each byte represents a beat
    // 00000000 = no note
    // 00011111 = 5 fret note
    byte *beats;
  };

#endif