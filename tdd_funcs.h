#ifndef TDD_FUNCS_H
#define TDD_FUNCS_H

#include <iostream>
#include <string>

#include "TM_Parser.h"

template <class T>
void assertEquals(  T const& actual,
                    T const& expected,
                    std::string message = "")
{
    if (expected == actual)
    {
        std::cout << "PASSED: " << message << std::endl;
    }
    else
    {
        std::cout <<    "  FAILED: " << message <<  std::endl <<
                        "      Expected: " <<       std::endl <<
                        expected <<                 std::endl <<
                        "      Actual: " <<         std::endl <<
                        actual <<                   std::endl;
    }
}

void assertEquals(  std::string actual,
                    std::string expected,
                    std::string message = "");
                    
void assertEquals(  char actual,
                    char expected,
                    std::string message = "");

void assertTrue(    bool expr,
                    std::string message = "");

void startTestGroup(std::string name);

#endif