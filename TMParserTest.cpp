#include <iostream>

#include "State.h"

int main()
{
    State s("q0", StateType::startStateType);
    s.addTransition('0', '0', Direction::dirL, "q1");
    s.addTransition('1', '1', Direction::dirR, "q2");
    s.addTransition('2', '2', Direction::dirL, "q3");
    s.addTransition('3', '3', Direction::dirR, "q4");

    std::cout << s << std::endl;
    return 0;
}