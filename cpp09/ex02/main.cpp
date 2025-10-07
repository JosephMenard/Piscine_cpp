#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: " << av[0] << " <numbers>" << std::endl;
        return 1;
    }
    else if (ac > 3001)
    {
        std::cerr << "Error: Too many arguments. Maximum is 3000." << std::endl;
        return 1;
    }
    try
    {
        PmergeMe pmerge(ac, av);
        pmerge.printContainers(1);
        double timeVector = pmerge.sortVector();
        double timeDeque = pmerge.sortDeque();
        pmerge.printContainers(2);
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector: " << std::fixed << std::setprecision(6) << timeVector << " seconds" << std::endl;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque: " << timeDeque << " seconds" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}