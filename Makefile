# _*_ Makefile _*_

CC=gcc
FLAGS= -Wall -g

all:  mainTrie.o trie1.o frequency

trie1.o: trie1.c trie1.h
	$(CC) $(FLAGS) -c  trie1.c

frequency: mainTrie.o trie1.o 
	$(CC) $(FLAGS) mainTrie.o trie1.o -o frequency

mainTrie.o: mainTrie.c trie1.h
	$(CC) $(FLAGS) -c  mainTrie.c


.PHONY: clean all 

clean:
	rm -f *.o frequency