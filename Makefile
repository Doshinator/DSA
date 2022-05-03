CC = g++
CFLAGS = -c -std=c++14
all: main

main: main.o array.o test.o two_ptr.o sliding_window.o
	$(CC) main.o array.o test.o two_ptr.o sliding_window.o -o main

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp 

array.o: array.cpp array.h
	$(CC) $(CFLAGS) array.cpp

two_ptr.o : two_ptr.cpp two_ptr.h
	$(CC) $(CFLAGS) two_ptr.cpp

test.o: test.cpp test.h
	$(CC) $(CFLAGS) test.cpp

sliding_window.o: sliding_window.cpp sliding_window.h
	$(CC) $(CFLAGS) sliding_window.cpp	
	
clean:
	rm *.o main