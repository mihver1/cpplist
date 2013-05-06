all: cpplist

cpplist: main.o list.h
	g++ main.o list.h -o main

list.o: list.h
	g++ -c list.h

main.o: main.cpp
	g++ -c main.cpp