CC=gcc

program: invent.o readline.o
	$(CC) -g -Wall -o program invent.o readline.o

invent.o: invent.c readline.h
readline.o: readline.c readline.h

clean:
	@rm -f *.o *.exe programi