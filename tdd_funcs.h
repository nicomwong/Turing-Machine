#ifndef TDD_FUNCS_H
#define TDD_FUNCS_H

#include <iostream>
#include <string>

#include "TM_Parser.h"

template <class T>
void assertEquals(  T const& expected,
                    T const& actual,
                    std::string message = "");

void assertEquals(  std::string expected,
                    std::string actual,
                    std::string message = "");
                    
void assertEquals(  char expected,
                    char actual,
                    std::string message = "");

void startTestGroup(std::string name);

#endif