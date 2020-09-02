#include "Transition.h"

class State
{
    public:
        /* Getter Member Functions */
        std::string getName();
        Transition* getTransition(char readSym); // retrieve transition and operation given a read symbol
        bool isAccepting(); // returns true if this is an accepting state, else returns false
        
        /* Setter Member Functions */
        void addTransition(char writeSymbol, direction dir, State* nextState); /* TO DO: make direction an enumator with proper syntax*/

    private:
        std::string name;
        std::vector<Transition> trans;
        bool accepting;
};