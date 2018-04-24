#Daniel Olivas
#CS162
#Assignment 1

all: Ant

Ant: main.o Ant.o Matrix.o
	g++ main.o Ant.o Matrix.o -o Ant

main.o: main.cpp
	g++ -c main.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

Matrix: Matrix.cpp Matrix.hpp
	g++ -c Matrix.cpp

clean:
	rm *o Ant