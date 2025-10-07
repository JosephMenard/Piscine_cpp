#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    AForm *shrubberry = new ShrubberyCreationForm("Shrubbery");
    AForm *robotomy = new RobotomyRequestForm("robotomy");
    AForm *presidential = new PresidentialPardonForm("presidential");
    Bureaucrat roger("roger", 150);
    Bureaucrat michel("michel", 5);
    std::cout << "\nshrubberry-->" << std::endl;
    roger.signForm(*shrubberry);
    michel.signForm(*shrubberry);
    std::cout << std::endl;
    michel.executeFrom(*shrubberry);
    roger.executeFrom(*shrubberry);
    std::cout << "\nrobotomy-->" << std::endl;
    roger.signForm(*robotomy);
    michel.signForm(*robotomy);
    std::cout << std::endl;
    michel.executeFrom(*robotomy);
    michel.executeFrom(*robotomy);
    roger.executeFrom(*robotomy);
    std::cout << "\npresidential-->" << std::endl;
    roger.signForm(*presidential);
    michel.signForm(*presidential);
    std::cout << std::endl;
    michel.executeFrom(*presidential);
    roger.executeFrom(*presidential);
    std::cout << std::endl;

    delete shrubberry;
    delete robotomy;
    delete presidential;
}