#include "RPN.hpp"

int main (int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Error: Usage: ./RPN number < 10 or + - * / " << std::endl;
        return 1;
    }
    try
    {
        RPN(std::string(av[1]));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n' << "Usage: Only number under 10 or '+', '-', '/', '*'" << std::endl;
        return 1;
    }
    return 0;
}