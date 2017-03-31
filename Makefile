CC=g++
CFLAGS=-c -Wall -std=c++11 -g

All : DBGen

DBGen : bd.o Interface.o Gorelki.o
	$(CC) bd.o Interface.o Gorelki.o -o a.out
	
bd.o : bd.cpp
	$(CC) $(CFLAGS) bd.cpp
	
Interface.o : Interface.cpp
	$(CC) $(CFLAGS) Interface.cpp
	
Gorelki.o : Gorelki.cpp
	$(CC) $(CFLAGS) Gorelki.cpp
	
clean : 
	rm -rf *.o a.out
	
