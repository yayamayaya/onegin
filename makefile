CC = g++
CFLAGS = -g -Wall -Wextra -DDEBUG -c

onegin:	 swap.o file_reader.o bsort.o onegin.o ../common/file_reading/bin/file_reading.o str_reader.o str_work.o
	$(CC) -g -Wall -o bin/onegin bin/bsort.o bin/onegin.o bin/swap.o bin/file_reader.o ../common/file_reading/bin/file_reading.o bin/str_reader.o bin/str_work.o

swap.o:		src/swap.cpp  src/include/swap.h
	$(CC) $(CFLAGS) src/swap.cpp -o bin/swap.o

file_reader.o:	src/w_file_read.cpp src/include/w_file_read.h
	$(CC) $(CFLAGS) src/w_file_read.cpp -o bin/file_reader.o

bsort.o:	src/bsort.cpp src/include/bsort.h
	$(CC) $(CFLAGS) src/bsort.cpp -o bin/bsort.o

onegin.o:	src/onegin.cpp
	$(CC) $(CFLAGS) src/onegin.cpp -o bin/onegin.o	

str_reader.o: src/string_reader.cpp src/include/string_reader.h
	$(CC) $(CFLAGS) $< -o bin/$@

str_work.o: src/string_work.cpp src/include/string_work.h
	$(CC) $(CFLAGS) $< -o bin/$@

all:
	$(CC) $(CFLAGS) -Wall -g src/swap.cpp src/fileReader.cpp src/bsort.cpp src/onegin.cpp -o bin/onegin

r:
	valgrind --leak-check=full --show-leak-kinds=all ./bin/onegin out.txt text.txt