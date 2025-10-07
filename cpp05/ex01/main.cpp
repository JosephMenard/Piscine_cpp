#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "\nTry and catch: creation" << std::endl;
    try
    {
        Form a("Form1", 0, 0);
    }
    catch(const Form::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form a("Form2", 151, 151);
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\nTry to sign" << std::endl;
    Bureaucrat michel("michel", 42);
    Form form("not for michel", 40, 1);
    Form form2("for michel", 45, 1);
    std::cout << std::endl;
    michel.signForm(form);
    std::cout << form << std::endl;
    std::cout << std::endl;
    michel.signForm(form2);
    std::cout << form2 << std::endl;
    std::cout << std::endl;
    return 0;
}