CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: sorts
	./sorts

sorts: main.o
	g++ -Wall -pedantic -std=c++0x -o sorts main.o



main.o: main.cpp mergesort.hh quicksort.hh introsort.hh heapsort.hh insertionsort.hh
	g++ -c ${CXXFLAGS} -o main.o main.cpp



clean:
	rm -f *.o sorts
