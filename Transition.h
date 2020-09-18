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
    Transition(char writeSym, Direction direction, std::string nextStateName);  // Parameterized Constructor

    /* Getter Member Functions */
    char getWrite() const;
    Direction getDirection() const;
    std::string getNextState() const;

    /* Overloaded Operators */
    bool operator==(Transition const& other);

private:
    char writeSym;
    Direction direction;
    std::string nextStateName;
};

#endif
