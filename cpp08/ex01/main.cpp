#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    sp.printSpan();

    int N = 10;
    Span test = Span(N);
    test.fillSpan();
    std::cout << test.longestSpan() << std::endl;
    std::cout << test.shortestSpan() << std::endl;
    test.printSpan();
    
    int N2 = 10000;
    Span test2 = Span(N2);
    test2.fillSpan();
    //test2.printSpan();

    Span test3(10);
    std::vector<int> numbers;
    numbers.push_back(6);
    numbers.push_back(3);
    numbers.push_back(17);
    numbers.push_back(9);
    numbers.push_back(11);
    test3.addRange(numbers.begin(), numbers.end());
    test3.printSpan();
    
    return 0;
}

// #include <iostream>
// #include <vector>
// #include "Span.hpp"

// int main()
// {
//     {
//         Span sp(5);
//         sp.addNumber(6);
//         sp.addNumber(3);
//         sp.addNumber(17);
//         sp.addNumber(9);
//         sp.addNumber(11);

//         std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
//         std::cout << "Longest span: "  << sp.longestSpan()  << std::endl;
//     }
//     {
//         Span sp(3);
//         try
//         {
//             sp.addNumber(1);
//             sp.addNumber(2);
//             sp.addNumber(3);
//             sp.addNumber(4);  // doit déclencher une exception
//         }
//         catch (const std::exception& e)
//         {
//             std::cout << "Over capacity: " << e.what() << std::endl;
//         }
//     }
//     {
//         Span sp(2);
//         try
//         {
//             sp.addNumber(10);
//             std::cout << sp.shortestSpan() << std::endl;
//         }
//         catch (const std::exception& e)
//         {
//             std::cout << "No span possible: " << e.what() << std::endl;
//         }
//     }
//     {
//         std::vector<int> v;
//         for (int i = 100; i < 110; ++i)
//             v.push_back(i);
//         Span sp(10);
//         try
//         {
//             sp.addRange(v.begin(), v.end());
//             std::cout << "Range added. Longest: " << sp.longestSpan()
//                       << ", Shortest: " << sp.shortestSpan() << std::endl;
//         }
//         catch (const std::exception&)
//         {
//             std::cout << "Range add failed" << std::endl;
//         }
//     }
//     {
//         Span sp(3);
//         sp.addNumber(5);
//         sp.addNumber(15);
//         sp.addNumber(25);
//         const Span& csp = sp;
//         std::cout << "Const shortest: " << csp.shortestSpan() << std::endl;
//         std::cout << "Const longest:  " << csp.longestSpan()  << std::endl;
//     }

//     return 0;
// }
