PROG=prog3
CC=g++
CPPFLAGS=-g -Wall -std=c++11

.PHONY: all

all:
	$(CC) $(CPPFLAGS) main.cpp prims.cpp -o $(PROG)

clean:
	rm -f *.o $(PROG) core
