#ifndef STATE_H
#define STATE_H

#include <unordered_map>
#include <ostream>
#include <string>

#include "Transition.h"

enum StateType
{
    normalStateType = 0,
    acceptStateType = 1,
    rejectStateType = 2,
    startStateType = 3,
};

std::ostream& operator<<(std::ostream& strm, StateType const& type);

class State
{
public:
    State(std::string name, StateType type); // Parameterized Constructor

    /* Getter Member Functions */
    std::string getName() const;
    StateType getType() const;
    Transition const* getTransition(char readSym) const;
    std::unordered_map<char, Transition> getTransitionMap() const;

    bool isAccepting() const;
    bool isRejecting() const;

    /* Setter Member Functions */
    void addTransition(char readSym, char writeSym, Direction dir, std::string nextStateName);

    /* Overloaded Operators */
    bool operator==(State const &other) const;

    friend std::ostream& operator<<(std::ostream& strm, State const& state);

private:
    std::string name;
    std::unordered_map<char, Transition> transition_map;
    StateType type;
};

#endif
