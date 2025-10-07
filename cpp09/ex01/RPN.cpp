#include "RPN.hpp"

void RPN::calculIt(void)
{
    std::list<int> stack;

    for (std::list<std::string>::const_iterator it = _list.begin();it != _list.end();++it)
    {
        const std::string nbr = *it;
        if (nbr == "+" || nbr == "-" || nbr == "*" || nbr == "/")
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error\n";
                return;
            }
            int right = stack.back(); 
            stack.pop_back();
            int left = stack.back(); 
            stack.pop_back();
            int result = 0;
            if      (nbr == "+") 
                result = left + right;
            else if (nbr == "-") 
                result = left - right;
            else if (nbr == "*") 
                result = left * right;
            else
            {
                if (right == 0.0f)
                {
                    std::cerr << "Error\n";
                    return;
                }
                result = left / right;
            }
            stack.push_back(result);
        }
        else
            stack.push_back(std::atoi(nbr.c_str()));
    }
    if (stack.size() != 1)
    {
        std::cerr << "Error\n";
        return;
    }
    std::cout << stack.back() << std::endl;
    return; 
}

bool RPN::parseList(std::string value, std::string& error_string)
{
    std::istringstream iss(value);
    std::string character;
    while (iss >> character)
        _list.push_back(character);
    for (std::list<std::string>::const_iterator it = _list.begin(); it != _list.end(); ++it)
    {
        std::string valeur = *it;
        if (valeur[0] != '+' && valeur[0] != '-' && valeur[0] != '*' && valeur[0] != '/')
        {
            errno = 0;
            char* endptr = NULL;
            double tmp = strtod(valeur.c_str(), &endptr);
            if (endptr == valeur.c_str() || *endptr != '\0' || errno == ERANGE)
                return error_string = valeur, false;
            if (std::floor(tmp) != tmp)
                return error_string = valeur, false;
            int value = static_cast<int>(tmp);
            if (value < 0 || value >= 10)
                return error_string = valeur, false;
        }
    }
    return true;
}

void RPN::printList(void)
{
    std::cout << "---LIST---" << std::endl;
    for (std::list<std::string>::const_iterator it = _list.begin(); it != _list.end(); it++)
    {
        std::cout << "=> " << *it << std::endl;
    }
}

RPN::RPN(std::string value)
{
    std::string error_string;
    if (!parseList(value, error_string))
        throw(InvalidEntry(error_string));
    calculIt();
}

RPN::~RPN(void)
{
}

const char* RPN::InvalidEntry::what() const throw()
{
    return _msg.c_str();
}

RPN::InvalidEntry::InvalidEntry(const std::string& msg)
{
  _msg = "Error: this char is invalid => '" + msg + "' ";
}

RPN::InvalidEntry::~InvalidEntry() throw()
{
}

