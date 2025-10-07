#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("default target")
{ 
    std::cout << "PresidentialPardonForm default constructor called" << std::endl; 
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm parameterized constructor called with param_target: " << target << std::endl; 
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("PresidentialPardonForm", 145, 137)
{ 
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl; 
    *this = other; 
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{ 
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &other)
        this->_target = other._target;
    return *this; 
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl; 
}

void PresidentialPardonForm::execute(Bureaucrat const& obj) const
{
    if (this->getIsSigned() == false)
        throw(FormNotSignedException());
    else if (obj.getGrade() > this->getToExec())
        throw(GradeTooLowException());
    else
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

