#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class Span
{
    private:
        std::vector<int> _container;
        unsigned int _N;

    public:
        Span(void);
        Span(unsigned int size);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span(void);

        void addNumber(int nbr);
        void fillSpan(void);
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan(void) const;
        int longestSpan(void) const;
        void printSpan(void) const;

        class SpanIsFull : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class SpanIsEmpty : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        

};

#endif
