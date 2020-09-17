#ifndef TRANSITION_H
#define TRANSITION_H

enum Direction
{
    dirL = 0,
    dirR = 1
};

class State; // forward declaration

class Transition
{
public:
    // Parameterized Constructor
    Transition(char writeSym, Direction direction, State* nextState);

    // Getter Member Functions
    char getWrite() const;
    Direction getDirection() const;
    State* getNextState() const;

private:
    char writeSym;
    Direction direction;
    State* nextState;
};

#endif
