#Makefile:                                                                                        

CC = g++
CFLAGS =-std=c++11 -pedantic -Wall -Wextra

digraph_analyzer: digraph_analyzer.o functions.o
	$(CC) -o digraph_analyzer digraph_analyzer.o functions.o  -g

digraph_analyzer.o: digraph_analyzer.cpp
	$(CC) $(CFLAGS) -c -g digraph_analyzer.cpp

functions.o: functions.cpp functions.h
	$(CC) $(CFLAGS) -c -g functions.cpp

clean:
	rm -f *.o digraph_analyzer *~
