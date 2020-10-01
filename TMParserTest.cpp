// TMParserTest.cpp

#include <iostream>

#include "TM_Parser.h"
#include "tdd_funcs.h"

void testTransition();
void testTransitionGetters();

void testState();
void testStateGetters();

int main()
{
    testTransition();
    return 0;
}

void testTransition()
{
    testTransitionGetters();
}

void testTransitionGetters()
{
    startTestGroup("Test Transition Getters");

    Transition t('a', 'b', Direction::dirL, "q1");
    assertEquals(t.getRead(), 'a', "getRead()");
    assertEquals(t.getWrite(), 'b', "getWrite()");
    assertEquals(t.getDirection(), Direction::dirL, "getDirection()");
    assertEquals(t.getNextState(), "q1", "getNextState()");
}