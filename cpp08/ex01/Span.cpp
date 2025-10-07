#include "Span.hpp"

void Span::addNumber(int nbr)
{
    if (this->_N <= this->_container.size())
        throw Span::SpanIsFull();
    _container.push_back(nbr);
}

int Span::shortestSpan(void) const
{
    int shortest = 2147483647;

    if (this->_container.size() < 2)
    throw Span::SpanIsEmpty();   
    
    std::vector<int> copy_cont(_container.begin(), _container.end());
    std::sort(copy_cont.begin(), copy_cont.end());

    for (size_t i = 0; i < copy_cont.size() - 1; i++)
    {
        if (copy_cont.at(i + 1) - copy_cont.at(i) < shortest)
            shortest = copy_cont.at(i + 1) - copy_cont.at(i);
    }
    return shortest;
}

int Span::longestSpan(void) const
{
    if (this->_container.size() < 2)
        throw Span::SpanIsEmpty();   
    
    std::vector<int> copy_cont(_container.begin(), _container.end());
    std::sort(copy_cont.begin(), copy_cont.end());

    return copy_cont.at(copy_cont.size() - 1) - copy_cont.at(0);
}

void Span::fillSpan(void)
{
    srand(time(NULL));

    for (unsigned int i = 0; i < _N; ++i)
    {
        addNumber(rand() % 10000);
    }
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator i = begin; i != end; ++i)
    {
        if (_container.size() >= _N)
            throw Span::SpanIsFull();
        _container.push_back(*begin);
        ++begin;
    }
}

Span::Span(void) : _N(10)
{ 
    std::cout << "Span default constructor called" << std::endl; 
}

Span::Span(unsigned int size) : _N(size)
{
    std::cout << "Span parameterized constructor called with param: " << size << std::endl; 
}

Span::Span(const Span& other) 
{ 
    std::cout << "Span copy constructor called" << std::endl; 
    *this = other; 
}

Span& Span::operator=(const Span& other)
{ 
    std::cout << "Span assignment operator called" << std::endl;
    if (this != &other)
        this->_N = other._N;
    return *this; 
}

Span::~Span(void)
{
    std::cout << "Span destructor called" << std::endl; 
}

const char* Span::SpanIsFull::what() const throw()
{
    return "Error: This Span is full !";
}

const char* Span::SpanIsEmpty::what() const throw()
{
    return "Error: This Span is empty or it has less than 2 number !";
}

void Span::printSpan(void) const
{
    for (size_t i = 0; i < _container.size(); ++i)
    {
        std::cout << _container[i] << " ";
    }
    std::cout << std::endl;
}
