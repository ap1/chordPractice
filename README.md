Chord Practice
==============

A simple tool for guitar beginners to practice chord transitions. It prints
random chord transitions at regular intervals (currently 5 seconds), showing
chord patterns with the names.

Data in **chords2.csv** courtesy of http://www.chordie.com/chords.php

Input
=====

Two input files are required:

* **chords2.csv** contains a database of chords with pattern codes (name,
  pattern, starting fret).

        A,x02220,1
        Am,x02210,1
        C,x32010,1
        D,xx0232,1
        D7,xx0212,1
        E,022100,1
        E7,020100,1
        Em,022000,1
        G,320003,1
        G7,320001,1

* **to\_test.txt** contains the list of names of chords for practice. The program will
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
* Display multi-character fret numbers without erroneous chars (:,;, etc.)
