// TM.cpp
#include <iostream> // possibly temporary

#include "TM.h"

TM::TM() : startState(nullptr)
{
}

TM::~TM()
{
    for (auto const& [stateName, statePtr] : this->state_map)
    {
        delete statePtr;
    }
}

bool TM::addState(std::string stateName, StateType type)
{
    State* s = new State(stateName, type);

    if (type == StateType::startStateType)
    {
        this->startState = s;
    }

    // If a state with name stateName exists, return false for failure
    if (this->state_map.count(stateName) == true)
    {
        return false;
    } else  // Else, insert the state and return true for success
    {
        this->state_map.insert({stateName, s});
        return true;
    }
}

bool TM::addTransition(std::string stateName, char readSym, char writeSym, Direction dir, std::string nextStateName)
{
    // If there is no state with name stateName, then print an error and stop
    if (state_map.count(stateName) == false)
    {
        std::cerr << "Error: No state with name '" << stateName << "' exists. Cannot create the transition" << std::endl;
        return false;   // Return false for failure
    }

    // Else, continue to define the transition
    this->addState(nextStateName, StateType::normalStateType);  // Attempt to add the next state

    State* const& s = this->state_map.at(stateName);
    s->addTransition(readSym, writeSym, dir, nextStateName);    // Add the transition

    return true;    // Return true for success
}

// Run the TM on the input string and return the resulting tape output string
std::string TM::run(std::string input)
{
    State* s = startState;
    int i = 0; // index for tape head

    if (s == nullptr)
    {
        // Check if start state is valid before dereferencing
        std::cout << "Error: startState is a nullptr" << std::endl;
        return input;
    }

    StateType type = s->getType();

    while (!(type == acceptStateType || type == rejectStateType))
    {
        char c = input.at(i);

        Transition const* trans = s->getTransition(c);
        input[i] = trans->getWrite();        // Write the symbol to the tape
        trans->getDirection() == 0 ? i-- : i++; // Move the position i according to the transition function
        s = this->state_map.at(trans->getNextState()); // Switch to the next state

        if (s == nullptr)
        {
            // Check if current state is valid before deref.
            std::cout << "Error: a transition leads to a nullptr as its nextState" << std::endl;
            return input;
        }

        type = s->getType();                    // Update current state type

        if (i > input.size() - 1)
        {
            // if moving R past end of tape, add a blank symbol '_'
            input.append("_");
        }

        if (i < 0)
        {
            // if moving L past beginning of tape, stay at leftmost position
            i = 0;
        }
    }

    return input;
}

bool TM::accepts(std::string input)
{
    State* s = startState;
    int i = 0; // index for tape head

    if (s == nullptr)
    {
        // Check if start state is valid before dereferencing
        std::cout << "Error: startState is a nullptr" << std::endl;
        return false;
    }

    StateType type = s->getType();

    while (!(type == acceptStateType || type == rejectStateType))
    {
        char c = input.at(i);

        Transition const* trans = s->getTransition(c);
        input.at(i) = trans->getWrite();        // Write the symbol to the tape
        trans->getDirection() == 0 ? i-- : i++; // Move the position i according to the transition function
        s = this->state_map.at(trans->getNextState());              // Switch to the next state

        if (s == nullptr)
        {
            // Check if current state is valid before deref.
            std::cout << "Error: a transition leads to a nullptr as its nextState" << std::endl;
            return false;
        }

        type = s->getType();                    // Update current state type

        if (i > input.size() - 1)
        {
            // if moving R past end of tape, add a blank symbol '_'
            input.append("_");
        }

        if (i < 0)
        {
            // if moving L past beginning of tape, stay at leftmost position
            i = 0;
        }
    }

    if (type == acceptStateType)
    {
        return true;
    }

    else // if (type == rejectStateType)
    {
        return false;
    }
}

bool TM::operator==(TM const& rhs)
{
    if (this->state_map.size() != rhs.state_map.size())
    {
        return false;
    }

    for (auto const& [stateName, statePtr] : this->state_map)
    {
        if (rhs.state_map.count(stateName) == 0 || (*statePtr != *rhs.state_map.at(stateName) ) )
        {
            return false;
        }
    }

    return true;
}

std::ostream& operator<<(std::ostream& strm, TM const& tm)
{
    strm << "Start State: " << tm.startState->getName() << std::endl;;
    for (auto const& [stateName, statePtr] : tm.state_map)
    {
        strm <<   "\t" << "State Name: " << stateName << std::endl << 
                    "\t" << "State Type: " << statePtr->getStringType() << std::endl;
        for (auto const& [readSym, trans] : statePtr->getTransitionMap() )
        {
            strm << "\t\t" << trans << std::endl;
        }
    } 
    return strm;  
}
