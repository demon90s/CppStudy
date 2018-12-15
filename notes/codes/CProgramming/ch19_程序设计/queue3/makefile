QUEUE_OBJ=queue.o

CC=g++ -std=c++11

program: main.o $(QUEUE_OBJ)
	$(CC) -g -Wall -o program main.o $(QUEUE_OBJ)

main.o: main.cpp queue.h
queue.o: queue.cpp queue.h

clean:
	@rm -f *.o *.exe program