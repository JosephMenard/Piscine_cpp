#include "iter.hpp"

void    foisDix(double &d) 
{
    d *= 10;
}

void printInt(int& value) 
{
    std::cout << value << std::endl;
}

void printDouble(double& value) 
{
    std::cout << value << std::endl;
}

void printString(std::string& value) 
{
    std::cout << value << std::endl;
}

int main()
{
    int    arr1[5] = {1, 2, 3, 4, 5};
    size_t len1   = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Integers: " << std::endl;
    ::iter(arr1, len1, printInt);
    std::cout << "\n";

    std::string arr2[4] = {"Salut", "Tout le monde", "Voici", "Mon cpp07"};
    size_t      len2   = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Strings:  " << std::endl;
    ::iter(arr2, len2, printString);
    std::cout << "\n";

    std::cout << "Empty:    " << std::endl;
    ::iter(arr1, 0, printInt);
    std::cout << "\n";

    std::cout << "fois 10: " << std::endl;
    double arr3[3] = {1.1, 2.2, 3.3};
    ::iter(arr3, 3, foisDix);
    ::iter(arr3, 3, printDouble);
    std::cout << "\n";

    return 0;
}
