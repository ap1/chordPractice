Chord Practice
==============

A simple tool for guitar beginners to practice chord transitions. It prints
random chord transitions at regular intervals (currently 5 seconds), showing
chord patterns with the names.

Input
=====

Two input files are required:

_chords.csv_ contains a database of chords with pattern codes.

    name,pattern
    A,x02220
    Am,x02210
    C,x32010
    D,xx0232
    D7,xx0212
    E,022100
    E7,020100
    Em,022000
    G,320003
    G7,320001

_to\_test.txt_ contains the list of names of chords for practice. The program will
only pick from these chords.

    Am,C,D,Em,G


Example Output (one chord)
==========================

    Chord Am (x02210)
    
      E A D G B E
        o       o
      -----------
    1 | | | | * |
    2 | | * * | |
    3 | | | | | |
    4 | | | | | |
    5 | | | | | |

TODO
====
* Add tunable time intervals
* Build bigger chord database
* Add difficulty information to chord database
* Support multi-character fret numbers
