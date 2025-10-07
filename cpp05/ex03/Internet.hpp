#ifndef INTERNET_HPP
#define INTERNET_HPP

#include <iostream>
#include "AForm.hpp"

class Internet
{
    public:
        Internet(void);
        Internet(const Internet& other);
        Internet& operator=(const Internet& other);
        ~Internet(void);

        AForm* makeForm(std::string wichForm, std::string targetForm);
};

#endif
