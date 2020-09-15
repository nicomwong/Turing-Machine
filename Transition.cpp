// Transition.cpp

#include "Transition.h"

/* Parameterized Constructor */
Transition::Transition(char write, Direction dir, State* next) :
    writeSym(write), direction(dir), nextState(next)
{
}

/* Getter Member Functions */
char Transition::getWrite()
{
    return this->writeSym;
}

Direction Transition::getDirection()
{
    return this->direction;
}

State* Transition::getNextState()
{
    return this->nextState;
}