#ifndef STATE_H
#define STATE_H

#include <unordered_map>
#include <string>

#include "Transition.h"

enum StateType
{
    normalStateType = 0,
    acceptStateType = 1,
    rejectStateType = 2,
    startStateType = 3,
};

class State
{
public:
    State(std::string name, StateType type); // Parameterized Constructor

    /* Getter Member Functions */
    std::string getName();
    StateType getType();  
    std::string getStringType();
    Transition *getTransition(char readSym);

    bool isAccepting();
    bool isRejecting();

    /* Setter Member Functions */
    void addTransition(char readSym, char writeSym, Direction dir, std::string nextStateName);

    /* Overloaded Operators */
    bool operator==(State const &other);

private:
    std::string name;
    std::unordered_map<char, Transition> transition_map;
    StateType type;
};

#endif
