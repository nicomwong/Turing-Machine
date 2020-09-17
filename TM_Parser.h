#ifndef TM_PARSER_H
#define TM_PARSER_H

#include <unordered_map>
#include <unordered_set>
#include <string>

#include "TM.h"

class TM_Parser
{
public:
    TM_Parser(std::string fileName);    // Parameterized constructor
    ~TM_Parser();                       // Destructor

    TM* parse(std::string fileName);

private:
    TM* printParseError(std::size_t pos, std::string descrip);
    void printError(std::size_t pos, std::string type, std::string descrip);

    TM* machine;

    std::unordered_set<char> alphabet;
};

#endif