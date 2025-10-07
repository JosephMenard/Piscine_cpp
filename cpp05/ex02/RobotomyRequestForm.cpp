#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default target")
{ 
    std::cout << "RobotomyRequestForm default constructor called" << std::endl; 
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm parameterized constructor called with param_target: " << target << std::endl; 
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 145, 137)
{ 
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl; 
    *this = other; 
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{ 
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &other)
        this->_target = other._target;
    return *this; 
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl; 
}

void RobotomyRequestForm::execute(Bureaucrat const& obj) const
{
    static int proba = 1;
    if (this->getIsSigned() == false)
        throw(FormNotSignedException());
    else if (obj.getGrade() > this->getToExec())
        throw(GradeTooLowException());
    else
    {
        if (proba % 2)
            std::cout << "FRRRRRRRRRRR\n" << this->_target << " has been robotomized !" << std::endl;
        else
            std::cout << "The robotomy of " << this->_target << " has failed !" << std::endl;
        proba++;
    }
}

