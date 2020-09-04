// Transition.cpp

#include "Transition.h"

/* Parameterized Constructor */
Transition::Transition(char write, Direction dir, State* next) :
    writeSym(write), direction(dir), nextState(next)
{
}

/* Getter Member Functions */
char Transition::getWriteSym()
{
    return writeSym;
}

Direction Transition::getDirection()
{
    return direction;
}

State* Transition::getNextState()
{
    return nextState;
}