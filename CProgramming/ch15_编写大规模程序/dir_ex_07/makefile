CC=gcc

demo: main.o f1.o f2.o
	$(CC) -o demo main.o f1.o f2.o

f1.o: f1.c f1.h f2.h
f2.o: f2.c f1.h f2.h
main.o: main.c f1.h

clean:
	@rm -f *.o *.exe main