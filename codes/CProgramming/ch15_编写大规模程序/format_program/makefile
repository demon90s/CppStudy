format: fmt.o word.o line.o
	gcc -o format fmt.o word.o line.o

fmt.o: fmt.c line.h word.h
	gcc -c fmt.c

line.o: line.c line.h
	gcc -c line.c

word.o: word.c word.h
	gcc -c word.c

clean:
	rm -f *.o format*
