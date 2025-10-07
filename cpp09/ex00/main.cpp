#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: Usage: ./btc <input_file> " << std::endl;
        return 1;
    }
    BitcoinExchange btc(av[1]);
    // btc.printData();
    btc.render();
    return 0;
}