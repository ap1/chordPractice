default:
	mkdir -p obj
	g++ -c src/chordDB.cpp -o obj/chordDB.o
	g++ -o chordPractice src/main.cpp obj/chordDB.o
