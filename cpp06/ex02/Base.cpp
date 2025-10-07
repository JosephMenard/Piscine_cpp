#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* Base::generate(void)
{
    srand(time(0));
    int rand_val = rand() % 3;

    if (rand_val == 0)
        return (new A());
    else if (rand_val == 1)
        return (new B());
    else
        return (new C());
}

void Base::identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "This Base class is A"<< std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "This Base class is B"<< std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "This Base class is C"<< std::endl;
}

void Base::identify(Base &p)
{
    identify(&p);
}

Base::Base(void) 
{ 
    std::cout << "Base default constructor called" << std::endl; 
}

Base::Base(const Base& other) 
{ 
    std::cout << "Base copy constructor called" << std::endl; 
    *this = other; 
}

Base& Base::operator=(const Base& other)
{ 
    (void) other;
    std::cout << "Base assignment operator called" << std::endl; 
    return *this; 
}

Base::~Base(void)
{
    std::cout << "Base destructor called" << std::endl; 
}

