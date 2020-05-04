#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: graf
	./graf

graf: main.o ListGraph.o MatrixGraph.o PriorityQueue.o
	g++ -Wall -pedantic -std=c++0x -o graf main.o ListGraph.o MatrixGraph.o PriorityQueue.o

main.o: main.cpp ListGraph.hh MatrixGraph.hh  GraphBase.hh dijkstra.hh
	g++ -c ${CXXFLAGS} -o main.o main.cpp

ListGraph.o: ListGraph.cpp ListGraph.hh GraphBase.hh
	g++ -c ${CXXFLAGS} -o ListGraph.o ListGraph.cpp

MatrixGraph.o: MatrixGraph.cpp MatrixGraph.hh GraphBase.hh
	g++ -c ${CXXFLAGS} -o MatrixGraph.o MatrixGraph.cpp
PriorityQueue.o: PriorityQueue.cpp PriorityQueue.hh
	g++ -c ${CXXFLAGS} -o PriorityQueue.o PriorityQueue.cpp


clean:
	rm -f *.o graf
