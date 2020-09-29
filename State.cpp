// State.cpp
#include <iostream> // possibly temporary

#include "State.h"

State::State(std::string name, StateType type) : name(name), type(type)
{
}

/* Getter Member Functions */

std::string State::getName() const
{
    return this->name;
}

StateType State::getType() const
{
    return this->type;
}   

Transition const* State::getTransition(char readSym) const
{
    if (transition_map.find(readSym) == transition_map.end())
    {
        std::cout << "Error: no transition found for read symbol " << readSym << " in state " << this->name << "." << std::endl;
        return nullptr;
    }

    else
    {
        return &transition_map.at(readSym);
    }
}

std::unordered_map<char, Transition> State::getTransitionMap() const
{
    return this->transition_map;
}

bool State::isAccepting() const
{
    return this->type == acceptStateType;
}

bool State::isRejecting() const
{
    return this->type == rejectStateType;
}

/* Setter Member Functions */

void State::addTransition(char readSym, char writeSym, Direction dir, std::string nextStateName)
{
    Transition t(readSym, writeSym, dir, nextStateName);
    transition_map.insert( {readSym, t} );
}

bool State::operator==(State const &other) const
{
    return this->name           ==  other.name              &&
           this->type           ==  other.type              &&
           this->transition_map ==  other.transition_map  ;
}

std::ostream& operator<<(std::ostream& strm, State const& state)
{
    strm << state.name << ", " << state.type << "\t";

    for (auto const& [readSym, trans] : state.transition_map)
    {
        strm << trans << " ";
    }

    return strm;
}

std::ostream& operator<<(std::ostream& strm, StateType const& type)
{
    std::string str("");

    switch (type)
    {
    case 0:     str = "normal"; 
    case 1:     str = "accept";  
    case 2:     str = "reject";  
    case 3:     str = "start"; 
    default:    str = "invalid";
    }
    strm << str;

    return strm;
}