#ifndef TRANSITION_H
#define TRANSITION_H

enum Direction
{
    dirL = 0,
    dirR = 1
};

class Transition
{
public:
    // Parameterized Constructor
    Transition(char writeSym, Direction direction, State* nextState);

    // Getter Member Functions
    char getWriteSym();
    Direction getDirection();
    State* getNextState();

private:
    char writeSym;
    Direction direction;
    State* nextState;
};

class State; // forward declaration

#endif
