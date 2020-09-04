#ifndef STATE_H
#define STATE_H

#include <unordered_map>
#include <string>

#include "Transition.h"

class State
{
    public:
        // Parameterized Constructor
        State(std::string name, bool isAccepting);

        /* Getter Member Functions */
        std::string getName();
        Transition* getTransition(char readSym);
        bool isAccepting();
        
        /* Setter Member Functions */
        void addTransition(char readSym, char writeSym, Direction dir, State* nextState);

    private:
        std::string name;
        std::unordered_map<char, Transition> transitions;
        bool accepting;
};

#endif