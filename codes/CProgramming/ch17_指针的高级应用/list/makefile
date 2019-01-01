CC=gcc

program: list.o main.o
	$(CC) -g -Wall -o program list.o main.o

list.o: list.c list.h
main.o: main.c list.h

clean:
	@rm -f *.o *.exe program