#include "tdd_funcs.h"

void assertEquals(  Transition const& expected,
                    Transition const& actual,
                    std::string message = "")
{
    if (expected == actual)
    {
        std::cout << "PASSED: " << message << std::endl;
    }
    else
    {
        std::cout << "  FAILED: " << message << std::endl;
        std::cout << "      Expected: " << expected << std::endl;
        std::cout << "      Actual: " << actual << std::endl;
    }
}

void assertEquals(  State const& expected,
                    State const& actual,
                    std::string message = "")
{
    if (expected == actual)
    {
        std::cout <<    "  PASSED: " << message << std::endl;
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

void assertEquals(  TM const& expected,
                    TM const& actual,
                    std::string message = "");

void assertEquals(  std::string expected,
                    std::string actual,
                    std::string message = "")
{
    if (expected == actual)
    {
        std::cout << "PASSED: " << message << std::endl;
    }
    else
    {
        std::cout <<    "  FAILED: " << message << std::endl <<
                        "       Expected: " << expected << " Actual: " << actual << std::endl;
    }
}

void startTestGroup(std::string name);