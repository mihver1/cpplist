all: cpplist

cpplist: main.o list.h
	g++ -g main.o list.h -o main

list.o: list.h
	g++ -c list.h -g

main.o: main.cpp
	g++ -c main.cpp -g