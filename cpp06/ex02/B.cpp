#include "B.hpp"

B::B(void) 
{ 
    std::cout << "B default constructor called" << std::endl; 
}

B::B(const B& other) 
{ 
    std::cout << "B copy constructor called" << std::endl; 
    *this = other; 
}

B& B::operator=(const B& other)
{
    (void) other;
    std::cout << "B assignment operator called" << std::endl; 
    return *this; 
}

B::~B(void)
{
    std::cout << "B destructor called" << std::endl; 
}

