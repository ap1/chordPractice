
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>

#include "common_inline.h"
#include "chordDB.h"

using namespace std;

int interval = 1;

int error(const string& msg);


int main(){

  string filenameChordDB    = "chords.csv";
  string filenameTestChords = "to_test.txt";

  chordDB db(filenameChordDB);

  ifstream fTestChords(filenameTestChords.c_str());

  if(!fTestChords.good()) error("cannot open test chords file\n");

  // first, create a vector for test chords
  string strTestChords;

  getline(fTestChords, strTestChords);

  vector<string> testChordNames;
  vtokenize(strTestChords, ",", testChordNames);

  if(testChordNames.size()==0) error("could not parse test chords string\n");

  if(testChordNames.size() <= 1){
    printf("Too few chords!\n");
    exit(1);
  }

  for(int i=0; i<(int)testChordNames.size(); i++){
    //printf("%s\n----\n",testChordNames[i].c_str());
    db.check(testChordNames[i]);
    //printf("\n\n");
  }

  int nTestChords = testChordNames.size();

  int lastTestChord = -1;

  srand((unsigned)time(0));

  while(1){

    screenclear();

    int nextTestChord;
    
    do{
      nextTestChord = rand() % nTestChords;
    }while(nextTestChord == lastTestChord);
    
    db.display(testChordNames[nextTestChord]);
    printf("\n\n");

    lastTestChord = nextTestChord;


    printf("5 "); fflush(stdout); dosleep(1000);
    printf("4 "); fflush(stdout); dosleep(1000);
    printf("3 "); fflush(stdout); dosleep(1000);
    printf("2 "); fflush(stdout); dosleep(1000);
    printf("1 "); fflush(stdout); dosleep(1000);

  }

  fTestChords.close();
}


int error(const string& msg){
  printf("%s\n",msg.c_str());
  exit(1);
}