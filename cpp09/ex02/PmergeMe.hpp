#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <exception>
#include <limits.h>
#include <stdexcept>


class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        bool parseInput(int ac, char **av, std::string&error);
        void algoVector(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void algoDeque(std::deque<int>::iterator begin, std::deque<int>::iterator end);

    public:
        PmergeMe(int ac, char **av);
        ~PmergeMe(void);
        void printContainers(int debug = 0);
        double sortVector(void);
        double sortDeque(void);

        class InvalidEntry : public std::exception
        {
            private:
                std::string _msg;
            public:
                InvalidEntry(const std::string& msg);
                virtual ~InvalidEntry() throw();
                virtual const char* what() const throw();
        };
};

#endif
