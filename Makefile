# _*_ Makefile _*_

all: frequency trie1.o

frequency:trie1.o 
	gcc -Wall -g -o frequency trie1.o

trie.o: trie1.c trie1.h
	gcc -Wall -g -c trie.c

.PHONY: clean all 

clean:
	rm -f *.o frequency