// TM_Parser.cpp

#include <sstream>
#include <iostream>
#include <fstream>
#include <regex>

#include "TM_Parser.h"

TM_Parser::TM_Parser(std::string fileName)
{
    this->machine = new TM();
    this->parse(fileName);
}

TM_Parser::~TM_Parser()
{
    delete this->machine;
}

TM* TM_Parser::parse(std::string fileName)
{
    std::ifstream my_istream(fileName); // Open fileName in input stream

    if (my_istream.is_open() == false)
    {
        std::cerr << "Error: The file with name " << fileName << " could not be opened in TM_Parser::parse()" << std::endl;
        return nullptr;
    }

    std::string line;

    // Parse the first 4 lines for alphabet, start, accept, and reject parameters
    for (int i = 1; i <= 4; i++)
    {
        if (std::getline(my_istream, line))
        {
            // Line 1: Define the alphabet
            if (i == 1)
            {
                std::regex r("^alphabet: ({(?:\\w, )*+\\w})");
                std::smatch m;
                std::regex_search(line, m, r);

                // Get the {csv} alphabet list from group 1
                std::string const& s = m.str(1);
                if (s != "")
                {
                    // Append every 3rd char starting at the 1st to the alphabet set
                    for (int j = 1; j < s.size() - 1; j+= 3)
                    {
                        this->alphabet.insert(s.at(j)); // *** Need to test ***
                    }
                } else
                {
                    return this->printParseError(my_istream.tellg(), "Failed to find list of alphabet chars");
                }
            }

            // Line 2: Define the start state
            else if (i == 2)
            {
                std::regex r("^start: (\\w++)$");
                std::smatch m;
                std::regex_search(line, m, r);

                // Get the start state name from group 1
                std::string const& s = m.str(1);
                if (s != "")
                {
                    this->machine->addState(s, StateType::startStateType);
                } else
                {
                    return this->printParseError(my_istream.tellg(), "Failed to find name of start state");
                }
            }

            // Line 3: Define the accept state
            else if (i == 3)
            {
                std::regex r("^accept: (\\w++)$");
                std::smatch m;
                std::regex_search(line, m, r);

                // Get the accept state name from group 1
                std::string const& s = m.str(1);

                // If the regex matched, then try to add the state
                if (s != "")
                {
                    this->machine->addState(s, StateType::acceptStateType);
                } else  // Else, print a parse error
                {
                    return this->printParseError(my_istream.tellg(), "Failed to find name of accept state");
                }
            }

            // Line 4: Define the reject state
            else // i == 4
            {
                std::regex r("^reject: (\\w++)$");
                std::smatch m;
                std::regex_search(line, m, r);

                // Get the reject state name from group 1
                std::string const& s = m.str(1);
                // If the regex matched, then try to add the state
                if (s != "")
                {
                    // Try to add the state. If it fails, then print an error that the accept state name was already taken and stop
                    if (this->machine->addState(s, StateType::rejectStateType) == false)
                    {
                        return this->printParseError(my_istream.tellg(), "Failed to set reject state name to " + s + "; name already taken");
                    }
                } else  // Else, print a parse error
                {
                    return this->printParseError(my_istream.tellg(), "Failed to find name of reject state");
                }
            }
        }

        // Else (if no line found with getline), print parse error
        else
        {
            std::ostringstream strm;
            strm << i;
            return this->printParseError(my_istream.tellg(), "Failed to find line " + strm.str() );
        }
    }
    
    // Make sure the next line is empty
    std::getline(my_istream, line);
    if (line != "")
    {
        return this->printParseError(my_istream.tellg(), "Expected empty line");
    }

    // Parse the remaining lines for state and transition definitions
    while (std::getline(my_istream, line))
    {
        // Find the state name
        std::regex r("^\\w++");
        std::smatch m;
        std::regex_search(line, m, r);
        
        std::string stateName = m.str(0);
        // Check if a state name is found
        if (stateName == "")
        {
            return this->printParseError(my_istream.tellg(), "Expected a definition of the state name");
        }

        // Add the state if it does not already exist
        this->machine->addState(stateName, StateType::normalStateType);

        // Change the active parsable string to the remains
        line = m.suffix().str();

        // Find the transition definition groups
        std::regex r_trans(" \\((\\w) -> (\\w), ([LR]), (\\w++)\\)");
        std::sregex_iterator rit(line.begin(), line.end(), r_trans);
        std::sregex_iterator rend; // Initializes as end_of_sequence iterator

        while (rit != rend)
        {
            m = *rit;
            
            // If no match found, then print a parse error
            if (m.size() == 0)
            {
                return this->printParseError(my_istream.tellg(), "Invalid transition definition syntax");
            }
            
            /* Now, full match found implies that groups 1-4 were found */

            /* Parse groups 1-4 in the transition match */

            // Get the read symbol from group 1
            char readSym = m.str(1).at(0);
            if (this->alphabet.count(readSym) == 0)
            {
                return this->printParseError(my_istream.tellg(), std::string(1, readSym) + " is not a valid read symbol in the defined alphabet"); // ** maybe add a wya to print the defined alphabet?
            }

            // Get the write symbol from group 2
            char writeSym = m.str(2).at(0);
            if (this->alphabet.count(writeSym) == 0)
            {
                return this->printParseError(my_istream.tellg(), std::string(1, writeSym) + " is not a valid write symbol in the defined alphabet"); // ** maybe add a wya to print the defined alphabet?
            }

            // Get the direction from group 3
            std::string dirStr = m.str(3);
            Direction dir;
            if (dirStr == "L" | dirStr == "R")
            {
                dir = dirStr == "L" ? Direction::dirL : Direction::dirR;
            } else
            {
                return this->printParseError(my_istream.tellg(), dirStr + " is not a valid Direction {L, R}");
            }
            
            // Get the name of the next state from group 4
            std::string nextStateName = m.str(4);

            // Add the transition to the state
            this->machine->addTransition(stateName, readSym, writeSym, dir, nextStateName);

            // Increment regex iterator
            rit++;
        }
    }

    // If this is reached, then no errors occurred. Return the machine
    return this->machine;
}

TM* TM_Parser::getMachine()
{
    return this->machine;
}

TM* TM_Parser::printParseError(std::size_t pos, std::string descrip)
{
    this->printError(pos, "Parse", descrip);
    return nullptr;
}

void TM_Parser::printError(std::size_t pos, std::string type, std::string descrip)
{
    std::cerr << type << " Error at position " << pos << ": " << descrip << "." << std::endl;
}