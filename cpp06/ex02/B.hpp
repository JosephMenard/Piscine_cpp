#ifndef B_HPP
#define B_HPP

#include <iostream>
#include "Base.hpp"

class B : public Base
{
    public:
        B(void);
        B(const B& other);
        B& operator=(const B& other);
        ~B(void);

};

#endif // B_HPP
