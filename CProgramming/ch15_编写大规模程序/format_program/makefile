format: fmt.o word.o line.o
	cc -o format fmt.o word.o line.o

fmt.o: fmt.c line.h word.h
	cc -c fmt.c

line.o: line.c line.h
	cc -c line.c

word.o: word.c word.h
	cc -c word.c

clean:
	rm -f *.o format
