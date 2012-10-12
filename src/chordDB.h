#ifndef chordDB_h
#define chordDB_h

#include "common_inline.h"
#include <string>
#include <fstream>
#include <map>

using namespace std;

class chordDB {

  map<string,string> chords;

  void checkPattern(const string& p);

  int getMinFret(string pat);
  int getMaxFret(string pat);
  int getFret(char c);

public:
  chordDB(const string& dbFileName);

  void display(const string& chordname);
  void check(const string& chordname);

};

#endif