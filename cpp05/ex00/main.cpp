#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "\nTry and catch: creation" << std::endl;
    try
    {
        Bureaucrat a("Eugene", 0);
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat a("Eustache", 151);
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "\nTry and catch: change grade" << std::endl;
    std::cout << "Malcolm: " << std::endl;
    Bureaucrat Malcolm("Malcolm", 1);
    try
    {
        Malcolm.promotion();
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << Malcolm << std::endl;
    std::cout << "Jack: " << std::endl;
    Bureaucrat Jack("Jack", 150);
    try
    {
        Jack.demotion();
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << Jack << std::endl;
    std::cout << "Patrick: " << std::endl;
    Bureaucrat Patrick("Patrick", 42);
    // while (1)
    //     Patrick.promotion(); //will create a segfault, because is not called with try catch
    try
    {
        Patrick.promotion();
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << Patrick << std::endl;
    std::cout << std::endl;
    return 0;
}