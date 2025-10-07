#include "Internet.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Internet::Internet(void) 
{ 
    std::cout << "Internet default constructor called" << std::endl; 
}

Internet::Internet(const Internet& other) 
{ 
    std::cout << "Internet copy constructor called" << std::endl; 
    *this = other; 
}

Internet& Internet::operator=(const Internet& other)
{
    (void)other;
    std::cout << "Internet assignment operator called" << std::endl; 
    return *this; 
}

Internet::~Internet(void)
{
    std::cout << "Internet destructor called" << std::endl; 
}

static AForm* makeShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm* makeRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm* makePresidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Internet::makeForm(std::string wichForm, std::string targetForm)
{
    int i = 0;
    AForm *(*forms[])(std::string target) = {&makeShrubbery, &makeRobotomy, &makePresidential};
    std::string formName[] = {"Shrubbery", "Robotomy", "Presidential"};
    while (i < 3)
    {
        if (formName[i] == wichForm)
        {
            std::cout << "Internet created: " << wichForm << " successfully !" << std::endl;
            return (forms[i](targetForm));
        }
        i++;
    }
    std::cout << "Internet cannot create: " << wichForm << " because he's do not exist !" << std::endl;
    return (NULL);
}
