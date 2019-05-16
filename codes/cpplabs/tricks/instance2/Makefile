CXXFLAGS=-std=c++11 -g -Wall
CC=g++

all: main

main: main.o instance.o

instance.o: instance.cpp
main.o: main.cpp instance.h

clean:
	@rm -f *.o main