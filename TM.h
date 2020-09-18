#ifndef TM_H
#define TM_H

#include <vector>

#include "State.h"

class TM
{
public:
    TM();
    ~TM();

    bool addState(std::string stateName, StateType stateType); // Add the state to the machine; returns false iff state with name stateName existed before
    bool addTransition(std::string stateName, char readSym, char writeSym, Direction dir, std::string nextStateName);   // Add the transition to the state pointed to by currentState; returns true iff transition was added successfully
                                                                                                                        // This function requires that a state with name stateName exists
                                                                                                                        // If no state with name nextStateName exists, it will be created (as a normal state type)
    /* In the future, the two above functions (or just addTransition())) will use exceptions instead of returning bool */

    std::string run(std::string input); // Runs the TM on the input and returns the resulting tape string
    bool accepts(std::string input); // Runs the TM on the input and returns whether it was accepted

private:
    void next(); // Perform the next state transition and corresponding operation
    void halt(bool accept); // Halt the machine; accept iff accept==true

    State* startState;
    std::unordered_map<std::string, State*> state_map;  // Maps state name to State*
};

#endif
