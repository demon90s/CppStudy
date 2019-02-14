all: main

main: main.o
	g++ -g -Wall main.o -o main

main.o: main.cpp Tiger.h Monster.h

CXXFLAGS=-g -Wall

CC=g++

clean:
	rm -f *.o main