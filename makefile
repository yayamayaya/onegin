onegin:		bsort.o swap.o file_reader.o onegin.o
	g++ -o bin/onegin bin/onegin.o bin/bsort.o bin/swap.o bin/file_reader.o

ro:



swap.o:		src/swap.cpp  src/swap.h
	g++ -Wall -g -c src/swap.cpp -o bin/swap.o

file_reader.o:	src/fileReader.cpp src/fileReader.h
	g++ -Wall -g -c src/fileReader.cpp -o bin/file_reader.o

bsort.o:	src/bsort.cpp src/bsort.h
	g++ -Wall -g -c src/bsort.cpp -o bin/bsort.o

onegin.o:	src/onegin.cpp src/main_header.h 
	g++ -Wall -g -c src/onegin.cpp -o bin/onegin.o	

all:
	g++ -Wall -g src/swap.cpp src/fileReader.cpp src/bsort.cpp src/onegin.cpp -o bin/onegin