// Transition.cpp
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
#include "Transition.h"

/* Parameterized Constructor */
Transition::Transition(char read, char write, Direction dir, std::string next) :
    readSym(read), writeSym(write), direction(dir), nextStateName(next)
{
}

/* Getter Member Functions */
char Transition::getRead() const
{
    return this->readSym;
}

char Transition::getWrite() const
{
    return this->writeSym;
}

Direction Transition::getDirection() const
{
    return this->direction;
}

std::string Transition::getNextState() const
{
    return this->nextStateName;
}

/* Overloaded Operators */
bool Transition::operator==(Transition const& other) const
{
    return  this->writeSym      ==  other.writeSym  &&
            this->direction     ==  other.direction &&
            this->nextStateName ==  other.nextStateName ;
}

std::ostream& operator<<(std::ostream& strm, Transition const& trans)
{
    return strm << "(read -> " << trans.writeSym << ", " << trans.direction << ", " << trans.nextStateName;
}