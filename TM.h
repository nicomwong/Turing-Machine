#include <vector>

#include "State.h"

class TM
{
    public:
        State* addState(std::string name, bool isAccepting); // add a state to the machine

    private:
        void next(); // perform next state transition and operation
        void halt(bool accept); // halt machine; accept if accept==true, else reject

        std::vector<char> alpha;
        State* start;
        State* accept;
        State* reject;
};