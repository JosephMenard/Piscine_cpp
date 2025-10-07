#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <cmath>

class RPN
{
    private:
        std::list<std::string> _list;
        bool parseList(std::string value, std::string& error_string);

    public:
        RPN(std::string param);
        ~RPN(void);
        void printList(void);
        void calculIt(void);

        class InvalidEntry : public std::exception
        {
            private:
                std::string _msg;
            public:
                InvalidEntry(const std::string& msg);
                virtual ~InvalidEntry() throw();
                virtual const char* what() const throw();
        };
};


#endif
