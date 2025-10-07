#include "C.hpp"

C::C(void) 
{ 
    std::cout << "C default constructor called" << std::endl; 
}

C::C(const C& other) 
{ 
    std::cout << "C copy constructor called" << std::endl; 
    *this = other; 
}

C& C::operator=(const C& other)
{
    (void) other;
    std::cout << "C assignment operator called" << std::endl;
    return *this; 
}

C::~C(void)
{
    std::cout << "C destructor called" << std::endl; 
}

