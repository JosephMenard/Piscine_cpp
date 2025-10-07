#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _tab(NULL), _size(0)
{ 
    std::cout << "Array default constructor called" << std::endl; 
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    if (n > 0)
        _tab = new T[n];
    else
        _tab = NULL;
    std::cout << "Array parameterized constructor called with size: " << n << std::endl; 
}

template <typename T>
Array<T>::Array(const Array<T>& other) : _size(other._size)
{ 
    std::cout << "Array copy constructor called" << std::endl; 
    if (other._size > 0)
    {
        _tab = new T[_size];
        for (size_t i = 0; i < other._size; ++i)
            _tab[i] = other._tab[i];
    }
    else
        _tab = NULL; 
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{ 
    std::cout << "Array assignment operator called" << std::endl;
    if (this != &other)
    {
        delete [] _tab;
        _size = other._size;
        if (other._size > 0)
        {
            _tab = new T[_size];
            for (size_t i = 0; i < other._size; ++i)
                _tab[i] = other._tab[i];
        }
        else
            _tab = NULL; 
    }
    return *this; 
}

template <typename T>
Array<T>::~Array(void)
{
    delete [] _tab;
    std::cout << "Array destructor called" << std::endl; 
}

template <typename T>
size_t Array<T>::size(void)
{
    return (_size);
}

template <typename T>
T& Array<T>::operator[](int index)
{
    size_t unsigned_index;

    if (index < 0)
        throw Array::IndexOutOfRange();
    else 
        unsigned_index = static_cast<size_t>(index);
    if (unsigned_index >= _size)
        throw Array::IndexOutOfRange();
    return _tab[unsigned_index];
}

template <typename T>
const char* Array<T>::IndexOutOfRange::what() const throw()
{
    return "Error: This index is out of range !";
}

