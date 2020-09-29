#ifndef TRANSITION_H
#define TRANSITION_H

#include <string>
#include <ostream>

// Maybe make Direction.h?
enum Direction
{
    dirL = 0,
    dirR = 1
};

std::ostream& operator<<(std::ostream& strm, Direction const& d);

class State; // forward declaration

class Transition
{
public:
    Transition(char readSym, char writeSym, Direction direction, std::string nextStateName);  // Parameterized Constructor

    /* Getter Member Functions */
    char getRead() const;
    char getWrite() const;
    Direction getDirection() const;
    std::string getNextState() const;

    /* Overloaded Operators */
    bool operator==(Transition const& other) const;

    friend std::ostream& operator<<(std::ostream& strm, Transition const& trans);
    
private:
    char readSym;
    char writeSym;
    Direction direction;
    std::string nextStateName;
};

#endif
