
#include "chordDB.h"

#include "common_inline.h"

chordDB::chordDB(const string& dbFileName){

  ifstream fChordDB(dbFileName.c_str());

  if(!fChordDB.good()){
    printf("cannot open chords db file %s\n",dbFileName.c_str());
    exit(1);
  }

  int lineno=0;

  while(fChordDB.good()){

    string line;

    getline(fChordDB, line);
    lineno++;

    if(line == "name,pattern" || (line.length() == 0) || (line == "\n")){
        continue;
    }

    printf("%s\n",line.c_str());

    vector<string> tokens;

    vtokenize(line, ",", tokens);

    if(tokens.size() < 2){
      printf("error parsing db line \"%s\"\n",line.c_str());
      exit(1);
    }

    addStartFret(tokens[1], tokens[2]);

    checkPattern(tokens[1]);

    chords[tokens[0]] = tokens[1];

  }

  fChordDB.close();
}

void chordDB::check(const string& chordname){
  if(!chords.count(chordname)){
    printf("Chord \"%s\" not found in database\n",chordname.c_str());
    exit(1);
  }
}

void chordDB::display(const string& chordname){
  if(chords.count(chordname)){
    printf("Chord %s (%s)\n\n",chordname.c_str(),chords[chordname].c_str());

    string pat = chords[chordname];

    int maxFret = getMaxFret(pat);
    int minFret = max(0,getMinFret(pat)-5);

    maxFret = max(maxFret, minFret+5);

    // print string names
    printf("     E A D G B E \n");

    for(int fret=minFret; fret <= maxFret; fret++){
      if(fret>0) printf(" %d  ", fret);
      else       printf("    ");
      for(int str=0; str<6; str++){
        if(getFret(pat[str]) == fret){
          if(fret==0) printf(" o");
          else        printf(" *");
        }else{
          if(fret==0) printf("  ");
          else        printf(" |");
        }
      }
      printf("\n");
      if(fret==0) printf("     ----------- \n");
    }

  }else{
    printf("Chord \"%s\" not found in database\n",chordname.c_str());
    exit(1);
  }
}


void chordDB::checkPattern(const string& p){

  if(p.length() == 6){
    for(int i=0; i<6; i++){
      switch(p[i]){
        case 'x':
        case '0'+0:
        case '0'+1:
        case '0'+2:
        case '0'+3:
        case '0'+4:
        case '0'+5:
        case '0'+6:
        case '0'+7:
        case '0'+8:
        case '0'+9:
        case '0'+10:
        case '0'+11:
        case '0'+12:
        case '0'+13:
        case '0'+14:
        case '0'+15:
        case '0'+16:
        case '0'+17:
        case '0'+18:
        case '0'+19:
          break;
        default:
          printf("Illegal character '%c' in \"%s\"\n",p[i],p.c_str());
          printf("Only x,0,1,2,3,4,5,6,7,8,9 are supported for now\n");
          exit(1);
      };
    }
  }else{
    printf("Illegal length of pattern in \"%s\"\n",p.c_str());
    printf("Only length-6 patterns are supported for now\n");
    exit(1);
  }
}


int chordDB::getMinFret(string& pat){
  int minFret=1000;
  for(int i=0; i<6; i++){
    int fret = getFret(pat[i]);
    if(fret > 0 && fret < minFret){
      minFret = fret;
    }
  }
  return minFret;
}

int chordDB::getMaxFret(string& pat){
  int maxFret=0;
  for(int i=0; i<6; i++){
    int fret = getFret(pat[i]);
    if(fret > 0 && fret > maxFret){
      maxFret = fret;
    }
  }
  return maxFret;
}

int chordDB::getFret(char c){
  switch(c){
    case 'x':     return -1;
    case '0'+0:   return  0;
    case '0'+1:   return  1;
    case '0'+2:   return  2;
    case '0'+3:   return  3;
    case '0'+4:   return  4;
    case '0'+5:   return  5;
    case '0'+6:   return  6;
    case '0'+7:   return  7;
    case '0'+8:   return  8;
    case '0'+9:   return  9;
    case '0'+10:  return  10;
    case '0'+11:  return  11;
    case '0'+12:  return  12;
    case '0'+13:  return  13;
    case '0'+14:  return  14;
    case '0'+15:  return  15;
    case '0'+16:  return  16;
    case '0'+17:  return  17;
    case '0'+18:  return  18;
    case '0'+19:  return  19;
      break;
    default:
      printf("Illegal fret %c\n",c);
      exit(1);
  };
}

void chordDB::addStartFret(string& pat, string& fret){
  int ifret = atol(fret.c_str());

  if(ifret <= 1) return;

  for(int i=0; i<6; i++){
    if(pat[i] != 'x'){
      pat[i] = pat[i] + (ifret - 1);
    }
  }
}