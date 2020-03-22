CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: structures
	./structures

structures: main.o
	g++ -Wall -pedantic -std=c++0x -o structures main.o



main.o: main.cpp node.hh ListIterator.hh ConstListIterator.hh List.hh Stack.hh Queue.hh PNode.hh PriorityQueue.hh Map.hh
	g++ -c ${CXXFLAGS} -o main.o main.cpp



clean:
	rm -f *.o structures
