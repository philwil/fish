# Makefile for pump tools
all: test test2 test3
test: test.cpp
	g++ -o test test.cpp
test2: test2.cpp
	g++ -o test2 test2.cpp

test3: test3.cpp
	g++ -o test3 test3.cpp -lpthread -lrt

clean:
	rm -f *.o
	rm -f test test2 test3
