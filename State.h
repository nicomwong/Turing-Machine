#ifndef STATE_H
#define STATE_H

#include <unordered_map>
#include <string>

#include "Transition.h"

enum StateType
{
    normalState = 0,
    acceptState = 1,
    rejectState = 2
};

class State
{
public:
    // Parameterized Constructor
    State(std::string name, StateType type);

    /* Getter Member Functions */
    std::string getName();
    Transition* getTransition(char readSym);
    bool isAccepting();
    bool isRejecting();

    /* Setter Member Functions */
    void addTransition(char readSym, char writeSym, Direction dir, State* nextState);

private:
    std::string name;
    std::unordered_map<char, Transition> transitions;
    StateType type;
};

#endif