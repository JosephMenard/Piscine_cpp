#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <limits>
#include <string>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter(void);

    public:
        static void convert(std::string src);
};

#endif
