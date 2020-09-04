// TM.cpp
#include <iostream> // possibly temporary

#include "TM.h"

TM::TM() : startState(nullptr), acceptState(nullptr), rejectState(nullptr), currentState(nullptr)
{
}

State* TM::addState(std::string name, bool isAccepting)
{
    State* s = new State(name, isAccepting);

    currentState = s;
    return s;
}

void TM::addTransition(char readSym, char writeSym, Direction dir, State* nextState)
{
    if (currentState != nullptr)
    {
        currentState->addTransition(readSym, writeSym, dir, nextState);
    }

    else
    {
        std::cout << "Error: Trying to add a transition but currentState == nullptr" << std::endl;
    }
}