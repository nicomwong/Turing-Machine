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

std::string State::getStringType() const
{  
    if (this->type == 0) return "normal"; 
    else if (this->type == 1) return "accept";  
    else if (this->type == 2) return "reject";  
    else if (this->type == 3) return "start";  
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
    transition_map[readSym] = t;
}

bool State::operator==(State const &other) const
{
    return this->name           ==  other.name              &&
           this->transition_map ==  other.transition_map    &&
           this->type           ==  other.type  ;
}

std::ostream& operator<<(std::ostream& strm, State const& state)
{
    strm << "State Name: " <<  state.name << "\n" << "State Type: " << state.getStringType() << "\n";
    for (auto const& [readSym, trans] : state.transition_map)
    {
      strm << "\t" << trans << "\n";
    }
    return strm;
}
