CXXFLAGS=-std=c++11 -g -Wall
CC=g++

all: main

main: main.o MemoryCounter.o

main.o: main.cpp MemoryCounter.h
MemoryCounter.o: MemoryCounter.cpp MemoryCounter.h

clean:
	rm -f *.o main