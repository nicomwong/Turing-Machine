CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wno-uninitialized

BINARIES = TMParserTest

test: TMParserTest
	./$^

TMParserTest: tdd_funcs.o TMParserTest.o TM_Parser.o TM.o State.o Transition.o
	${CXX} $^ -o $@

tdd_funcs.o: tdd_funcs.cpp
	${CXX} ${CXXFLAGS} -c $^

TMParserTest.o: TMParserTest.cpp
	${CXX} ${CXXFLAGS} -c $^

TM_Parser.o: TM_Parser.cpp
	${CXX} ${CXXFLAGS} -c $^

TM.o: TM.cpp
	${CXX} ${CXXFLAGS} -c $^

State.o: State.cpp
	${CXX} ${CXXFLAGS} -c $^
	
Transition.o: Transition.cpp
	${CXX} ${CXXFLAGS} -c $^

clean:
	/bin/rm -f ${BINARIES} *.o
