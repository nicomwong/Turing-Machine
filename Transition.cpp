// Transition.cpp

#include "Transition.h"

/* Parameterized Constructor */
Transition::Transition(char write, Direction dir, State* next) :
    writeSym(write), direction(dir), nextState(next)
{
}

/* Getter Member Functions */
char Transition::getWrite() const
{
    return this->writeSym;
}

Direction Transition::getDirection() const
{
    return this->direction;
}

State* Transition::getNextState() const
{
    return this->nextState;
}