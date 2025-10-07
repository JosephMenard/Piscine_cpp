#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* src)
{
    std::cout << "serializer called !" << std::endl;
    return (reinterpret_cast<uintptr_t>(src));
}

Data* Serializer::deserialize(uintptr_t src)
{
    std::cout << "deserializer called !" << std::endl;
    return (reinterpret_cast<Data*>(src));
}

Serializer::Serializer(void)
{ 
    std::cout << "Serializer default constructor called" << std::endl; 
}

Serializer::Serializer(const Serializer& other) 
{ 
    std::cout << "Serializer copy constructor called" << std::endl; 
    *this = other; 
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    std::cout << "Serializer assignment operator called" << std::endl;
    return *this;
}

Serializer::~Serializer(void)
{
    std::cout << "Serializer destructor called" << std::endl; 
}
