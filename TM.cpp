// TM.cpp
#include <iostream> // possibly temporary

#include "TM.h"

TM::TM() : startState(nullptr), currentState(nullptr)
{
}

TM::~TM()
{
    delete this->startState;
    /*  SCHEMATIC FOR RECURSIVE DESTRUCTOR
     *  1. If this state is nullptr, then return
     *  2. For each [read, t] : state_map, 
     *      a. If t->nextState was traversed through to get here, then do nothing
     *      b. Else, remember this state and recursively destruct t->nextState
     *  3. Delete this state
     */
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
    s->addTransition(readSym, writeSym, dir, this->state_map.at(nextStateName));    // Add the transition
    
    return true;    // Return true for success
}

// Run the TM on the input string and return the resulting tape output string
std::string TM::run(std::string input)
{
    State *s = startState;
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

        Transition *trans = s->getTransition(c);
        input[i] = trans->getWrite();        // Write the symbol to the tape
        trans->getDirection() == 0 ? i-- : i++; // Move the position i according to the transition function
        s = trans->getNextState();              // Switch to the next state

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

        Transition *trans = s->getTransition(c);
        input.at(i) = trans->getWrite();        // Write the symbol to the tape
        trans->getDirection() == 0 ? i-- : i++; // Move the position i according to the transition function
        s = trans->getNextState();              // Switch to the next state

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