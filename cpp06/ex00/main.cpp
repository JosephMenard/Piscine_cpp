#include "ScalarConverter.hpp"
int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "enter at least one argument" << std::endl;
        return (1);
    }
    for (int i = 1; i < ac; i++)
    {
        std::cout << std::endl;
        ScalarConverter::convert(std::string(av[i]));
    }
    return (0);
}