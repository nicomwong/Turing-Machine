#ifndef TM_PARSER_H
#define TM_PARSER_H

#include <unordered_map>
#include <unordered_set>
#include <string>

#include "TM.h"

// Currently, the TM_Parser class only supports holding one TM at a time

class TM_Parser
{
public:
    // Parameterized constructor
    TM_Parser(std::string fileName);

    void parse(std::string fileName);

    TM* getMachine(); // Returns a pointer to the TM that the parser currently holds
private:
    std::unordered_map<std::string, State*> states;
    std::unordered_set<char> alphabet;
};

#endif