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
    Transition(char writeSym, Direction direction, std::string nextStateName);

    // Getter Member Functions
    char getWrite() const;
    Direction getDirection() const;
    std::string getNextState() const;

private:
    char writeSym;
    Direction direction;
    std::string nextStateName;
};

#endif
