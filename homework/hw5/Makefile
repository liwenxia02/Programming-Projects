#Makefile:                                                                                        

CC = g++
CFLAGS =-std=c++11 -pedantic -Wall -Wextra

digraph_analyzer: digraph_analyzer.o
	$(CC) -o digraph_analyzer digraph_analyzer.o -g

digraph_analyzer.o: digraph_analyzer.cpp
	$(CC) $(CFLAGS) -c -g digraph_analyzer.cpp

clean:
	rm -f *.o digraph_analyzer *~
