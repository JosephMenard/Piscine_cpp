#include "ScalarConverter.hpp"

std::string ft_replace(std::string line)
{
    int         i  = 0;
    size_t      is_find = 0;
    std::string s1 = ",";
    std::string s2 = ".";

    while ((is_find = line.find(s1, i)) != std::string::npos)
    {
        line.erase(is_find, s1.size());
        line.insert(is_find, s2);
        i = is_find + s2.size();
    }
    
    return (line);
}

void ScalarConverter::convert(std::string src)
{
    char *end;
    src = ft_replace(src);
    double value = std::strtod(src.c_str(), &end);

    if (*end != '\0' && value == 0.0)
    {
        if (src.length() != 1)
        {
            std::cerr << "Error: " << src << " can't be convert !" << std::endl;
            return;
        }
        else
            value = src[0];
    }
    if (std::isnan(value))
    {
        std::cout << "Convert to CHAR: Impossible" << std::endl;
        std::cout << "Convert INT: Impossible" << std::endl;
        std::cout << "Convert to FLOAT: nanf" << std::endl;
        std::cout << "Convert to DOUBLE: nan" << std::endl;
        return;
    }
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "Convert to CHAR: Impossible" << std::endl;
    else if (!isprint(static_cast<char>(value)))
        std::cout << "Convert to CHAR: Non Displayable" << std::endl;
    else
        std::cout << "Convert to CHAR: <" << static_cast<char>(value) << ">" << std::endl;
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "Convert INT: Impossible" << std::endl;
    else
        std::cout << "Convert to INT: <" << static_cast<int>(value) << ">" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Convert to FLOAT: <" << static_cast<float>(value) << "f>" << std::endl;
    std::cout << "Convert to DOUBLE: <" << value << ">" << std::endl;
}

ScalarConverter::ScalarConverter(void)
{ 
    std::cout << "ScalarConverter default constructor called" << std::endl; 
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{ 
    std::cout << "ScalarConverter copy constructor called" << std::endl; 
    *this = other; 
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    std::cout << "ScalarConverter assignment operator called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter(void)
{
    std::cout << "ScalarConverter destructor called" << std::endl; 
}
