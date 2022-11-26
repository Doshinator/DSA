CC = g++
CFLAGS = -c -std=c++17
all: main

main: main.o array.o test.o two_ptr.o sliding_window.o stack.o binary_search.o linked_list.o trees.o trie.o heap.o backtracking.o graphs.o dp.o
	$(CC) main.o array.o test.o two_ptr.o sliding_window.o stack.o binary_search.o linked_list.o trees.o trie.o heap.o backtracking.o graphs.o dp.o -o main

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp 

array.o: array.cpp array.h
	$(CC) $(CFLAGS) array.cpp

two_ptr.o: two_ptr.cpp two_ptr.h
	$(CC) $(CFLAGS) two_ptr.cpp

test.o: test.cpp test.h
	$(CC) $(CFLAGS) test.cpp

sliding_window.o: sliding_window.cpp sliding_window.h
	$(CC) $(CFLAGS) sliding_window.cpp	

stack.o: stack.cpp stack.h
	$(CC) $(CFLAGS) stack.cpp

binary_search.o: binary_search.cpp binary_search.h
	$(CC) $(CFLAGS) binary_search.cpp

linked_list.o: linked_list.cpp linked_list.h
	$(CC) $(CFLAGS) linked_list.cpp

trees.o: trees.cpp trees.h
	$(CC) $(CFLAGS) trees.cpp

trie.o : trie.cpp trie.h
	$(CC) $(CFLAGS) trie.cpp 

heap.o: heap.cpp heap.h
	$(CC) $(CFLAGS) heap.cpp

backtracking.o : backtracking.cpp backtracking.h
	$(CC) $(CFLAGS) backtracking.cpp

graphs.o : graphs.cpp graphs.h
	$(CC) $(CFLAGS) graphs.cpp

dp.o : dp.cpp dp.h
	$(CC) $(CFLAGS) dp.cpp

clean:
	rm *.o main