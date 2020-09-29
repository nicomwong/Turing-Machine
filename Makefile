CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wno-uninitialized

BINARIES = TMParserTest


test: TMParserTest.o State.o Transition.o
	${CXX} $^ -o $@

TMParserTest.o: TMParserTest.cpp
	${CXX} ${CXXFLAGS} -c $^

State.o: State.cpp
	${CXX} ${CXXFLAGS} -c $^
	
Transition.o: Transition.cpp
	${CXX} ${CXXFLAGS} -c $^

clean:
	/bin/rm -f ${BINARIES} *.o
