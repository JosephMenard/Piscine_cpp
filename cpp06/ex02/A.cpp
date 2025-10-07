#include "A.hpp"

A::A(void) 
{ 
    std::cout << "A default constructor called" << std::endl; 
}

A::A(const A& other) 
{ 
    std::cout << "A copy constructor called" << std::endl; 
    *this = other; 
}

A& A::operator=(const A& other)
{
    (void) other;
    std::cout << "A assignment operator called" << std::endl;
    return *this; 
}

A::~A(void)
{
    std::cout << "A destructor called" << std::endl; 
}

