#include "tdd_funcs.h"

template <class T>
void assertEquals(  T const& expected,
                    T const& actual,
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

void assertEquals(  char expected,
                    char actual,
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
        std::cout <<    "  FAILED: " << message <<              std::endl <<
                        "       Expected:   " << expected <<    std::endl <<
                        "       Actual:     " << actual <<      std::endl;
    }
}

void startTestGroup(std::string name)
{
    std::cout << "--------------" << name << "--------------" << std::endl;
}