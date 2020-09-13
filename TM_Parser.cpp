// TM_Parser.cpp

#include <iostream>
#include <fstream>
#include <regex>

#include "TM_Parser.h"

TM_Parser::TM_Parser(std::string fileName) : machine(nullptr)
{
    this->parse(fileName);
}

TM* TM_Parser::getMachine()
{
    return this->machine;
}

void TM_Parser::printParseError(std::size_t pos, std::string descrip)
{
    std::cerr << "Parse Error at position " << pos << ": " << descrip << "." << std::endl;
}