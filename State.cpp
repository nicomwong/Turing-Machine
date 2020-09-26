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

StateType State::getType()
{
    return this->type;
}

Transition *State::getTransition(char readSym)
{
    if (transition_map.find(readSym) == transition_map.end())
    {
        std::cout << "Error: no transition found for read symbol " << readSym << " in state " << this->name << "." << std::endl;
        return nullptr;
    }

    else
    {
        return &transition_map[readSym];
    }
}

bool State::isAccepting()
{
    return this->type == acceptStateType;
}

bool State::isRejecting()
{
    return this->type == rejectStateType;
}

/* Setter Member Functions */

void State::addTransition(char readSym, char writeSym, Direction dir, std::string nextStateName)
{
    Transition t(readSym, writeSym, dir, nextStateName);
    transition_map[readSym] = t;
}

bool State::operator==(State const &other)
{
    return this->name           ==  other.name              &&
           this->transition_map ==  other.transition_map    &&
           this->type           ==  other.type  ;
}