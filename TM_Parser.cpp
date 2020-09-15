// TM_Parser.cpp

#include <iostream>
#include <fstream>
#include <regex>

#include "TM_Parser.h"

TM_Parser::TM_Parser(std::string fileName)
{
    this->machine = new TM();
    this->parse(fileName);
}

TM* TM_Parser::parse(std::string fileName)
{
    std::ifstream my_istream(fileName); // Open fileName in output stream

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
                const std::string& s = m.str(1);
                if (s != "")
                {
                    for (int j = 1; j < s.size() - 1; j+= 3)
                    {
                        this->alphabet.insert(s.at(j)); // *** Need to test ***
                    }
                } else
                {
                    this->printParseError(my_istream.tellg(), "Failed to find list of alphabet chars");
                    return nullptr;
                }
                
            }

            // Line 2: Define the start state
            else if (i == 2)
            {
                std::regex r("^start: (\\w++)$");
                std::smatch m;
                std::regex_search(line, m, r);

                // Get the start state name from group 1
                const std::string& s = m.str(1);
                if (s != "")
                {
                    this->machine->addState(s, StateType::startStateType);
                } else
                {
                    this->printParseError(my_istream.tellg(), "Failed to find name of start state");
                    return nullptr;
                }
            }

            // Line 3: Define the accept state
            else if (i == 3)
            {
                std::regex r("^accept: (\\w++)$");
                std::smatch m;
                std::regex_search(line, m, r);

                // Get the accept state name from group 1
                const std::string& s = m.str(1);
                if (s != "")
                {
                    this->machine->addState(s, StateType::acceptStateType);
                } else
                {
                    this->printParseError(my_istream.tellg(), "Failed to find name of accept state");
                    return nullptr;
                }
            }

            // Line 4: Define the reject state
            else // i == 4
            {
                std::regex r("^reject: (\\w++)$");
                std::smatch m;
                std::regex_search(line, m, r);

                // Get the reject state name from group 1
                const std::string& s = m.str(1);
                if (s != "")
                {
                    this->machine->addState(s, StateType::rejectStateType);
                } else
                {
                    this->printParseError(my_istream.tellg(), "Failed to find name of reject state");
                    return nullptr;
                }
                
            }
        }

        // If no line found, print parse error
        else
        {
            this->printParseError(my_istream.tellg(), "Failed to find line " + i);
            return nullptr;
        }
    }
    
    // Make sure the next line is empty
    std::getline(my_istream, line);
    if (line != "")
    {
        this->printParseError(my_istream.tellg(), "Expected empty line");
        return nullptr;
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
            this->printParseError(my_istream.tellg(), "Expected a definition of the state name");
            return nullptr;
        }

        State* state = nullptr;
        /* TO DO: Abstract the next 10 lines into a function */
        // Check if a state with this name was already created
        // If so, get the pointer and set it
        if (this->state_map.count(stateName) == 1)
        {
            state = state_map.at(stateName);
        } else  // Else, create the state, set it, and add it to the map
        {
            state = machine->addState(stateName, StateType::normalStateType);
            state_map.insert({stateName, state});
        }

        // Change the active parsable string to the remains
        line = m.suffix().str();

        // Find the transition definition groups
        std::regex r_trans(" \\((\\w) -> (\\w), ([LR]), (\\w++)\\)");
        std::sregex_iterator rit(line.begin(), line.end(), r_trans);
        std::sregex_iterator rend; // Represents end_of_sequence iterator

        while (rit != rend)
        {
            m = *rit;
            
            // If no match found, then print a parse error
            if (m.size() == 0)
            {
                this->printParseError(my_istream.tellg(), "Invalid transition definition syntax");
                return nullptr;
            }
            
            // Now, full match found implies groups 1-4 were found

            // Parse groups 1-4 in the transition match

            // Get the read symbol from group 1
            char readSym = m.str(1).at(0);
            if (this->alphabet.count(readSym) == 0)
            {
                this->printParseError(my_istream.tellg(), readSym + " is not a valid read symbol in the defined alphabet"); // ** maybe add a wya to print the defined alphabet?
                return nullptr;
            }

            // Get the write symbol from group 2
            char writeSym = m.str(2).at(0);
            if (this->alphabet.count(writeSym) == 0)
            {
                this->printParseError(my_istream.tellg(), writeSym + " is not a valid write symbol in the defined alphabet"); // ** maybe add a wya to print the defined alphabet?
                return nullptr;
            }

            // Get the direction from group 3
            char dirChar = m.str(3).at(0);
            Direction dir;
            if (dirChar == 'L' | dirChar == 'R')
            {
                dir = dirChar == 'L' ? Direction::dirL : Direction::dirR;
            } else
            {
                this->printParseError(my_istream.tellg(), dirChar + " is not a valid Direction {L, R}");
                return nullptr;
            }
            
            // Get the name of the next state from group 4
            std::string nextStateName = m.str(4);
            State* nextState = nullptr;

            /* TO DO: Abstract the next 10 lines into a function */
            // Check if a state with this name was already created
            // If so, get the pointer and set it
            if (this->state_map.count(nextStateName) == 1)
            {
                nextState = state_map.at(nextStateName);
            } else  // Else, create the state, set it, and add it to the map
            {
                nextState = machine->addState(nextStateName, StateType::normalStateType);
                state_map.insert({nextStateName, nextState});
            }

            // Add the transition to the state
            state->addTransition(readSym, writeSym, dir, nextState);

            // Increment regex iterator
            rit++;
        }
    }

    return this->machine;
}

void TM_Parser::printParseError(std::size_t pos, std::string descrip)
{
    std::cerr << "Parse Error at position " << pos << ": " << descrip << "." << std::endl;
}