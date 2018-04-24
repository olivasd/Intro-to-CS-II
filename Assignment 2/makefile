#Daniel Olivas
#CS162
#Assignment 2

all: list

list: main.o list.o item.o
	g++ main.o list.o item.o -o list

main.o: main.cpp
	g++ -c main.cpp

list.o: list.cpp list.hpp
	g++ -c list.cpp

item: item.cpp item.hpp
	g++ -c item.cpp

clean:
	rm *o list