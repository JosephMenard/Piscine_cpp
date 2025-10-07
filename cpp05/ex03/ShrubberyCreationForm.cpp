#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default target")
{ 
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm parameterized constructor called with param_target: " << target << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", 145, 137)
{ 
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl; 
    *this = other; 
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{ 
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &other)
        this->_target = other._target;
    return *this; 
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl; 
}

void ShrubberyCreationForm::execute(Bureaucrat const& obj) const
{
    if (this->getIsSigned() == false)
        throw(FormNotSignedException());
    else if (obj.getGrade() > this->getToExec())
        throw(GradeTooLowException());
    else
    {
        std::ofstream file;
        file.open((this->_target + "_shrubbery").c_str());
        if (!file) 
        {
            std::cerr << "Error: Could not create file " << _target << "_shrubbery" << std::endl;
            return;
        }
        file << "        *        " << std::endl;
        file << "       ***       " << std::endl;
        file << "      *****      " << std::endl;
        file << "     *******     " << std::endl;
        file << "    *********    " << std::endl;
        file << "   ***********   " << std::endl;
        file << "  *************  " << std::endl;
        file << " *************** " << std::endl;
        file << "*****************" << std::endl;
        file << "       |||       " << std::endl;
        file << "       |||       " << std::endl;
        file.close();
    }
}

