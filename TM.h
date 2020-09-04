#ifndef TM_H
#define TM_H

#include <vector>
#include <unordered_set>

#include "State.h"

class TM
{
public:
    TM();

    State* addState(std::string name, StateType type); // Add the state to the machine
    void addTransition(char readSym, char writeSym, Direction dir, State* nextState); // Add the transition to the state pointed to by currentState

    std::string run(std::string input); // Runs the TM on the input and returns the resulting tape string
    bool accepts(std::string input); // Runs the TM on the input and returns whether it was accepted

private:
    void next(); // Perform the next state transition and corresponding operation
    void halt(bool accept); // Halt the machine; accept iff accept==true

    State* startState;
    State* acceptState;
    State* rejectState;
    State* currentState; // Tracks the current state in order to allow the transitions to be defined
};

#endif
