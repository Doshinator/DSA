CC = g++
CFLAGS = -c -std=c++14
all: main

main: main.o array.o test.o
	$(CC) main.o array.o test.o -o main

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp 

array.o: array.cpp array.h
	$(CC) $(CFLAGS) array.cpp

test.o: test.cpp test.h
	$(CC) $(CFLAGS) test.cpp
clean:
	rm *.o main