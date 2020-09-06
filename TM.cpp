// TM.cpp
#include <iostream> // possibly temporary

#include "TM.h"

TM::TM() : startState(nullptr), acceptState(nullptr), rejectState(nullptr), currentState(nullptr)
{
}

State* TM::addState(std::string name, StateType type)
{
    State* s = new State(name, type);

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
        input[i] = trans->getWriteSym();        // Write the symbol to the tape
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

bool TM:accepts(std::string input)
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

        Transition *trans = s->getTransition(c);
        input[i] = trans->getWriteSym();        // Write the symbol to the tape
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

    if (type == acceptStateType)
    {
        return true;
    }
    
    else // if (type == rejectStateType)
    {
        return false;
    }
}