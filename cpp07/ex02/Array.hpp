#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T* _tab;
        size_t _size;

    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array(void);
        T& operator[](int index);
        size_t size(void);


        class IndexOutOfRange : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

#include "Array.tpp"

#endif
