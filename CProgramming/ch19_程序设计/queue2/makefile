QUEUE_OBJ=queue.o

CC=gcc

program: main.o $(QUEUE_OBJ)
	$(CC) -g -Wall -o program main.o $(QUEUE_OBJ)

main.o: main.c queue.h
queue.o: queue.c queue.h
queue_impl2.o: queue_impl2.c queue.h

clean:
	@rm -f *.o *.exe program