#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x
CXYFLAGS= -lsfml-graphics -lsfml-window -lsfml-system --std=c++14

__start__: warcaby
	./warcaby

warcaby: main.o Board.o Game.o
	g++ -Wall -pedantic -std=c++0x -o warcaby main.o Board.o Game.o ${CXYFLAGS}
main.o: main.cpp Board.hh Game.hh
	g++ -c ${CXXFLAGS} -o main.o main.cpp ${CXYFLAGS}
Board.o: Board.cpp Board.hh
	g++ -c ${CXXFLAGS} -o Board.o Board.cpp ${CXYFLAGS}
Game.o: Game.cpp Game.hh Board.hh
	g++ -c ${CXXFLAGS} -o Game.o Game.cpp ${CXYFLAGS}

clean:
	rm -f *.o warcaby
