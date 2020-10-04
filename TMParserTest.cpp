// TMParserTest.cpp

#include <iostream>

#include "TM_Parser.h"
#include "tdd_funcs.h"

void testTransitionGetters();
void testTransitionOperatorEquals();

void testStateGetters();

int main()
{
    testTransitionGetters();
    testTransitionOperatorEquals();

    testStateGetters();
    return 0;
}

void testTransitionGetters()
{
    startTestGroup("Test Transition Getters");

    Transition t('a', 'b', Direction::dirL, "q1");
    assertEquals(t.getRead(), 'a', "getRead()");
    assertTrue( !(t.getRead() == 'b'), "getRead()");

    assertEquals(t.getWrite(), 'b', "getWrite()");
    assertTrue( !(t.getWrite() == 'c'), "getWrite()");

    assertEquals(t.getDirection(), Direction::dirL, "getDirection()");
    assertTrue( !(t.getDirection() == Direction::dirR), "getDirection()");
    
    assertEquals(t.getNextState(), "q1", "getNextState()");
    assertTrue( !(t.getNextState() == "q3"), "getNextState()");
}

void testTransitionOperatorEquals()
{
    startTestGroup("Test Transition Operator ==");

    Transition t1('a', 'b', Direction::dirL, "q1");
    Transition t2('a', 'b', Direction::dirL, "q1");
    assertTrue(t1 == t2, "Equivalent");

    Transition t3('a', 'b', Direction::dirL, "q0");
    assertTrue( !(t1 == t3), "Different nextState");

    Transition t4('a', 'b', Direction::dirR, "q1");
    assertTrue( !(t1 == t4), "Different direction");

    Transition t5('a', 'c', Direction::dirL, "q0");
    assertTrue( !(t1 == t5), "Different write");

    Transition t6('b', 'c', Direction::dirL, "q0");
    assertTrue( !(t1 == t6), "Different read");

    Transition t7('b', 'c', Direction::dirR, "q3");
    assertTrue( !(t1 == t7), "Different everything");
}

void testStateGetters()
{
    startTestGroup("Test State Getters");

    State s("q0", StateType::startStateType);
    
    /* Test getName() */
    assertEquals(s.getName(), "q0", "getName()");
    assertTrue( !(s.getName() == "q1"), "getName()");

    /* Test getType() */
    assertEquals(s.getType(), StateType::startStateType, "getType()");
    assertTrue( !(s.getType() == StateType::normalStateType), "getType()");

    /* Test isAccepting() and isRejecting() */
    assertTrue( !s.isAccepting(), "isAccepting()");
    assertTrue( !s.isRejecting(), "isRejecting()");

    State s_acc("acc", StateType::acceptStateType);
    assertTrue(s_acc.isAccepting(), "isAccepting()");
    
    State s_rej("rej", StateType::rejectStateType);
    assertTrue(s_rej.isRejecting(), "isRejecting()");

    /* Test getTransition() */

    assertEquals<Transition>(s.getTransition('a'), nullptr, "No transitions");    
}