// ---------------------------------------------------
//  Written by Anjul Patney in 2010
// ---------------------------------------------------

#ifndef common_inline_h
#define common_inline_h

#include <string>
#include <vector>
#include <list>
#include <math.h>
#include <cstdlib>
#include <sstream>
#include <assert.h>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#endif

// useful macros
#define __DEB                    {printf("Reached %s (%d)\n",__FILE__,__LINE__);}
#define __ERR                    {printf("ERROR AT %s (%d)\n",__FILE__,__LINE__); exit(1);}
#define RAND_01                  ((float)rand()/(float)RAND_MAX)
#define TIME_SO_FAR(reason,...)  {printf("----> Time : %0.2f [", ((float)(clock()-frameStartTime))/(float)CLOCKS_PER_SEC); printf(reason,__VA_ARGS__); printf("]\n");}
#define assertPrint(expr,msg,...){if(!(expr)){printf("[ASSERT] "); printf(msg,__VA_ARGS__); assert(0);}}
#define raise(msg,...)           {assertPrint(0,msg,__VA_ARGS__);}
#define DeleteIfNotNull(x)       {if(x!=NULL){delete    x ; x=NULL;}}
#define DeleteArrayIfNotNull(x)  {if(x!=NULL){delete [] x ; x=NULL;}}

inline void vtokenize(const std::string& str,const std::string& delimiters, std::vector<std::string> &tokens)
{
    tokens.clear();
    if(str=="") return;
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    std::string::size_type pos = str.find_first_of(delimiters, lastPos);
    while (std::string::npos != pos || std::string::npos != lastPos)
    {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
}

inline void dosleep( int ms )
{
#ifdef _WIN32
  Sleep(ms); // If Windows, use Sleep() from windows.h
#else
  usleep( ms * 1000 ); // If *nix, use usleep() from unistd.h
#endif
}

inline void screenclear(){
#ifdef _WIN32
  system("CLS");
#else
  system("clear");
#endif
}

#endif
