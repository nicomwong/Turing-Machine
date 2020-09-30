#include "tdd_funcs.h"

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
                    std::string message = "")
{
    if (expected == actual)
    {
        std::cout << "PASSED: " << message << std::endl;
    }
    else
    {
        std::cout <<    "  FAILED: " << message <<              std::endl <<
                        "       Expected:   " << expected <<    std::endl <<
                        "       Actual:     " << actual <<      std::endl;
    }
}

void assertEquals(  char actual,
                    char expected,
                    std::string message = "")
{
    if (expected == actual)
    {
        std::cout << "PASSED: " << message << std::endl;
    }
    else
    {
        std::cout <<    "  FAILED: " << message <<              std::endl <<
                        "       Expected:   " << expected <<    std::endl <<
                        "       Actual:     " << actual <<      std::endl;
    }
}

void startTestGroup(std::string name)
{
    std::cout << "--------------" << name << "--------------" << std::endl;
}