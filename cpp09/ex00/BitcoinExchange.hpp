#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <cstring> 
#include <iomanip>
#include <cctype>

class BitcoinExchange
{
    private:
        std::multimap<std::string, float> _data;
        std::string _file_name;
        void parseData(void);
        bool checkInput(std::string& line, std::string date, float value) const;
        float doConversion(std::string date, float value) const;

    public:
        BitcoinExchange(std::string value);
        ~BitcoinExchange(void);
        void printData(void) const;
        void render(void) const;



};

#endif
