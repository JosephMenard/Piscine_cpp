#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
    protected:
        Base(void);
        Base(const Base& other);
        Base& operator=(const Base& other);

    public:
        virtual ~Base(void);
        static Base* generate(void);
        static void identify(Base *p);
        static void identify(Base &p);

};

#endif 
