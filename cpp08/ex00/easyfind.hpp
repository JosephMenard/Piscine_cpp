#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

template <typename T>
typename T::iterator easyfind(T &container, int entier)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), entier);
    if (it == container.end())
        std::cerr << "Error: int not found in container !" << std::endl;
    return (it);
}


#endif

