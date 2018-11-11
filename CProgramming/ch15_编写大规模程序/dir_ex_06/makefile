CC=gcc

main: main.o stack.o token.o
	gcc -g -Wall -o main main.o stack.o token.o

main.o: main.c stack.h token.h
stack.o: stack.c stack.h
token.o: token.c token.h

clean:
	@rm -f main *.o *.exe
