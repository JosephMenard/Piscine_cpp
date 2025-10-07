#include "PmergeMe.hpp"

void PmergeMe::algoDeque(std::deque<int>::iterator begin, std::deque<int>::iterator end)
{
    bool hasLast = false;
    std::deque<int> max;
    std::deque<int> min;
    size_t deq_size = end - begin;

    if (deq_size <= 1) 
    return;
    int last = 0;
    if (deq_size % 2 == 1) 
    {
        hasLast = true;
        last = *(end - 1);
        deq_size--;
    }
    for (size_t i = 0; i < deq_size; i += 2)
    {
        int first = *(begin + i);
        int second = *(begin + i + 1);
        if (first < second) {
            max.push_back(second);
            min.push_back(first);
        } else {
            max.push_back(first);
            min.push_back(second);
        }
    }
    algoDeque(max.begin(), max.end());
    std::deque<int> retour = max;
    int numFollowers = min.size();
    for (int i = numFollowers - 1; i >= 0; i--) 
    {
        int value = min[i];
        std::deque<int>::iterator pos = std::lower_bound(retour.begin(), retour.end(), value);
        retour.insert(pos, value);
    }
    if (hasLast)
    {
        std::deque<int>::iterator pos = std::lower_bound(retour.begin(), retour.end(), last);
        retour.insert(pos, last);
    }
    for (size_t i = 0; i < retour.size(); i++) {
        *(begin + i) = retour[i];
    }
}

void PmergeMe::algoVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    bool hasLast = false;
    std::vector<int> max;
    std::vector<int> min;
    size_t vec_size = end - begin;

    if (vec_size <= 1) 
        return;
    int last = 0;
    if (vec_size % 2 == 1) 
    {
        hasLast = true;
        last = *(end - 1);
        vec_size--;
    }
    for (size_t i = 0; i < vec_size; i += 2)
    {
        int first = *(begin + i);
        int last = *(begin + i + 1);
        if (first < last) {
            max.push_back(last);
            min.push_back(first);
        } else {
            max.push_back(first);
            min.push_back(last);
        }
    }
    algoVector(max.begin(), max.end());
    std::vector<int> retour = max;
    int numFollowers = min.size();
    for (int i = numFollowers - 1; i >= 0; i--) 
    {
        int value = min[i];
        std::vector<int>::iterator pos = std::lower_bound(retour.begin(), retour.end(), value);
        retour.insert(pos, value);
    }
    if (hasLast)
    {
        std::vector<int>::iterator pos = std::lower_bound(retour.begin(), retour.end(), last);
        retour.insert(pos, last);
    }
    for (size_t i = 0; i < retour.size(); i++) {
        *(begin + i) = retour[i];
    }
}

double PmergeMe::sortVector(void)
{
    std::clock_t start = std::clock();
    algoVector(_vector.begin(), _vector.end());
    return static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
}

double PmergeMe::sortDeque(void)
{
    std::clock_t start = std::clock();
    algoDeque(_deque.begin(), _deque.end());
    return static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

bool PmergeMe::parseInput(int ac, char **av, std::string& error)
{
    for (int i = 1; i < ac; i++)
    {
        char* endptr = NULL;
        long val = std::strtol(av[i], &endptr, 10);
        
        if (av[i][0] == '\0' || (av[i][0] == '0' && av[i][1] != '\0')) 
            return error = std::string(av[i]), false;
        if (*endptr != '\0')
            return error = std::string(av[i]), false;
        if (val < 0 || val > INT_MAX)
            return error = std::string(av[i]), false;

        int valid = static_cast<int>(val);
        _vector.push_back(valid);
        _deque.push_back(valid);
    }
    return true;
}

void PmergeMe::printContainers(int debug)
{
    if (debug == 0)
    {
        std::cout << "Vector: ";
        for (size_t i = 0; i < _vector.size(); i++)
        {
            std::cout << _vector[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Deque: ";
        for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    else if (debug == 1)
    {
        std::cout << "Before: ";
        for (size_t i = 0; i < _vector.size(); i++)
        {
            std::cout << _vector[i];
            if (i < _vector.size() - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    else if (debug == 2)
    {
        std::cout << "After: ";
        for (size_t i = 0; i < _vector.size(); i++)
        {
            std::cout << _vector[i];
            if (i < _vector.size() - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

PmergeMe::~PmergeMe(void) 
{ 
    std::cout << "PmergeMe destructor called" << std::endl; 
}

PmergeMe::PmergeMe(int ac, char **av) 
{
    std::string error_msg;
    if (!parseInput(ac, av, error_msg))
        throw InvalidEntry(error_msg);
}

const char* PmergeMe::InvalidEntry::what() const throw()
{
    return _msg.c_str();
}

PmergeMe::InvalidEntry::InvalidEntry(const std::string& msg)
{
  _msg = "Error: this token is not a positive int=> '" + msg + "' ";
}

PmergeMe::InvalidEntry::~InvalidEntry() throw()
{
}

