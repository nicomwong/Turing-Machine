// Transition.cpp

#include <string>

#include "Transition.h"

/* Parameterized Constructor */
Transition::Transition(char write, Direction dir, std::string next) :
    writeSym(write), direction(dir), nextStateName(next)
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

std::string Transition::getNextState() const
{
    return this->nextStateName;
}