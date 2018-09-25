# Makefile for the fishtank series

all: fish fish2 fishVec fishVec2

fish: fish.cpp 
	g++ -g -o fish  fish.cpp

fish2: fish2.cpp 
	g++ -g -o fish2 fish2.cpp	

fishVec: fishVec.cpp 
	g++ -g -o $@ $<

fishVec2: fishVec2.cpp 
	g++ -g -o $@ $<


clean:
	rm -rf fish fish2 fishVec fishVec2 *.o
