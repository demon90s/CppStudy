CXXFLAGS=-std=c++11 -g -Wall
CC=g++

all: main

main: main.o Node.o

main.o: main.cpp Node.h
Node.o: Node.cpp Node.h

clean:
	@rm -f *.o main