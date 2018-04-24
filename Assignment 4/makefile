#Daniel Olivas
#CS162
#Assignment 4

all: battle

battle: main.o vampire.o barbarian.o blueMen.o medusa.o harryPotter.o queue.o stack.o tournament.o
	g++ main.o vampire.o barbarian.o blueMen.o medusa.o harryPotter.o queue.o stack.o tournament.o -o battle

main.o: main.cpp
	g++ -c main.cpp

vampire.o: vampire.cpp vampire.h
	g++ -c vampire.cpp

barbarian.o: barbarian.cpp barbarian.h
	g++ -c barbarian.cpp

blueMen.o: blueMen.cpp blueMen.h
	g++ -c blueMen.cpp

medusa.o: medusa.cpp medusa.h
	g++ -c medusa.cpp

harryPotter.o: harryPotter.cpp harryPotter.h
	g++ -c harryPotter.cpp

queue.o: queue.cpp queue.h
	g++ -c queue.cpp

stack.o: stack.cpp stack.h
	g++ -c stack.cpp

tournament.o: tournament.cpp tournament.h
	g++ -c tournament.cpp

clean:
	-rm -f *o battle