EXEC=main
CXXFLAGS=-g -Wall -std=c++11

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

all:$(OBJS)
	g++ -o $(EXEC) $(OBJS)
	@echo build succ
.c.o:
	g++ -o $@ -c $<
clean:
	@rm -f $(OBJS) $(EXEC)
