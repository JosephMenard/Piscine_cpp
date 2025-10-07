#include "MutantStack.hpp"

int main() {
    //Tests basiques push / top / pop / size
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    //Remplissage et itération avant
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "Elements in stack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    //Itération inverse
    std::cout << "Elements in reverse: ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    //Test du constructeur de copie
    MutantStack<int> copyStack(mstack);
    std::cout << "Copy elements: ";
    for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    //Test de l’itération sur instance const
    const MutantStack<int> constStack(mstack);
    std::cout << "Const elements: ";
    for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
