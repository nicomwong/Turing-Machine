#ifndef TDD_FUNCS_H
#define TDD_FUNCS_H

#include <iostream>
#include <string>

#include "TM_Parser.h"

void assertEquals(  Transition const& expected,
                    Transition const& actual,
                    std::string message = "");

void assertEquals(  State const& expected,
                    State const& actual,
                    std::string message = "");

void assertEquals(  TM const& expected,
                    TM const& actual,
                    std::string message = "");

void assertEquals(  std::string expected,
                    std::string actual,
                    std::string message = "");

void startTestGroup(std::string name);

#endif