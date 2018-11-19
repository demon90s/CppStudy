CC=gcc

main: main.o stack.o
	gcc -g -Wall -o main main.o stack.o

main.o: main.c stack.h
stack.o: stack.c stack.h

clean:
	@rm -f main *.o *.exe
