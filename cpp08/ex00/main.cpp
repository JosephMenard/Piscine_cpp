#include "easyfind.hpp"

int main(int ac, char **av)
{
    if (ac != 3)
    {
        std::cerr << "Error: enter tow number !, First arg: size of container, Second arg: number to find" << std::endl;
        return (1);
    }
    std::vector<int> container;
    std::vector<int>::iterator it;

    std::cout << "Creation of container; " << std::endl;
    for (int i = 0; i < atoi(av[1]); i++)
    {
        srand(i * time(0));
        int rand_value = rand() %atoi(av[1]);
        std::cout << rand_value << std::endl;
        container.push_back(rand_value);
    }
    it = easyfind(container, atoi(av[2]));
    if (it == container.end())
        return (1);
    else
       std::cout << "Value: " << *it << " is find !" << std::endl;
    return (0); 
}

// #include <iostream>
// #include <vector>
// #include <list>
// #include <deque>
// #include "easyfind.hpp"

// int main()
// {
//     {
//         std::vector<int> v;
//         for (int i = 0; i < 5; ++i)
//             v.push_back(i * 2);  // [0,2,4,6,8]
//         try
//         {
//             std::vector<int>::iterator it = easyfind(v, 4);
//             std::cout << "Found in vector: " << *it << std::endl;
//         }
//         catch (const std::exception& e)
//         {
//             std::cerr << "Error: " << e.what() << std::endl;
//         }
//     }
//     {
//         std::vector<int> v;
//         v.push_back(1);
//         v.push_back(3);
//         v.push_back(5);
//         try
//         {
//             easyfind(v, 2);
//         }
//         catch (const std::exception& e)
//         {
//             std::cout << "Not found as expected: " << e.what() << std::endl;
//         }
//     }
//     {
//         std::list<int> lst;
//         for (int i = 10; i < 15; ++i)
//             lst.push_back(i);
//         try
//         {
//             std::list<int>::iterator it = easyfind(lst, 12);
//             std::cout << "Found in list: " << *it << std::endl;
//         }
//         catch (const std::exception&)
//         {
//             std::cout << "List search failed" << std::endl;
//         }

//         std::deque<int> dq;
//         dq.push_back(7);
//         dq.push_back(8);
//         dq.push_back(9);
//         try
//         {
//             std::deque<int>::iterator it2 = easyfind(dq, 9);
//             std::cout << "Found in deque: " << *it2 << std::endl;
//         }
//         catch (const std::exception&)
//         {
//             std::cout << "Deque search failed" << std::endl;
//         }
//     }
//     {
//         std::vector<int> v;
//         v.push_back(42);
//         std::vector<int>& rv = v;
//         try
//         {
//             std::vector<int>::iterator itr = easyfind(rv, 42);
//             std::cout << "Found via reference: " << *itr << std::endl;
//         }
//         catch (const std::exception&)
//         {
//         }
//     }

//     return 0;
// }

