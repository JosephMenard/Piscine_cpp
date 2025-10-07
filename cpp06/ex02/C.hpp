#ifndef C_HPP
#define C_HPP

#include <iostream>
#include "Base.hpp"

class C : public Base
{
    public:
        C(void);
        C(const C& other);
        C& operator=(const C& other);
        ~C(void);

};

#endif
