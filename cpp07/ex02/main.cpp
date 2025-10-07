#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 5

int main(int, char**)
{
    //////////TEST CLASS ET REMPLISSAGE
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "tmp size: " << tmp.size() << "\ntmp value:" << std::endl;
        for (size_t i = 0; i < MAX_VAL; i++)
            std::cout << "\t" << tmp[i] << std::endl;
        std::cout << "test size: " << test.size() << "\ntest value:" << std::endl;
        for (size_t i = 0; i < MAX_VAL; i++)
            std::cout << "\t" << test[i] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    //////////TEST TRY & CATCH
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " (for index -2)\n";
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " (for index MAX_VAL)\n";
    }
    try
    {
        numbers[MAX_VAL / 2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " (for index MAX_VAL)\n";
    }
    std::cout << "numbers size: " << numbers.size() << "\nnumbers value:" << std::endl;
    for (size_t i = 0; i < MAX_VAL; i++)
        std::cout << "\t" << numbers[i] << std::endl;
    //////////TEST DE RE REMPLISSAGE
    for (int i = 0; i < MAX_VAL; i++)
        numbers[i] = rand();
    std::cout << "numbers size after change: " << numbers.size() << "\nnumbers value:" << std::endl;
    for (size_t i = 0; i < MAX_VAL; i++)
        std::cout << "\t" << numbers[i] << std::endl;
    delete [] mirror;
    return 0;
}