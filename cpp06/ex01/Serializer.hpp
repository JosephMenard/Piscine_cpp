#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include <string>

struct Data
{
    std::string name;
    int number;
};

class Serializer
{
    private:
        Serializer(void);
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer(void);

    public:
        static uintptr_t serialize(Data* src);
        static Data* deserialize(uintptr_t src);
};

#endif
