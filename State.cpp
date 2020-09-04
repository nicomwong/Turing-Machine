// State.cpp
#include <iostream> // possibly temporary

#include "State.h"

State::State(std::string name, StateType type) : name(name), type(type)
{
}

/* Getter Member Functions */

std::string State::getName()
{
    return this->name;
}

Transition* State::getTransition(char readSym)
{
    if (transitions.find(readSym) == transitions.end())
    {
        std::cout << "Error: no transition found for read symbol " << readSym << " in state " << this->name << "." << std::endl;
        return nullptr;
    }

    else
    {
        return &transitions[readSym];
    }
}

bool State::isAccepting()
{
    return this->type == acceptState;
}

bool State::isRejecting()
{
    return this->type == rejectState;
}

/* Setter Member Functions */

void State::addTransition(char readSym, char writeSym, Direction dir, State* nextState)
{
    Transition t(writeSym, dir, nextState);
    transitions[readSym] = t;
}