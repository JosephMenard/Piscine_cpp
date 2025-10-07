#include "AForm.hpp"

void AForm::beSigned(Bureaucrat& obj)
{
    if (obj.getGrade() > this->_toSign)
        throw (AForm::GradeTooLowException());
    else if (this->_isSigned == true)
        std::cout << "AForm: " << this->_name << " is already signed" << std::endl;
    else
    {
        std::cout << "AForm: " << this->_name << " has be signed by: " << obj.getName() << std::endl;
        this->_isSigned = true;
    }
}

AForm::AForm(void) : _name("no name"), _toSign(150), _toExec(150), _isSigned(false)
{ 
    std::cout << "AForm default constructor called" << std::endl; 
}

AForm::AForm(std::string const& name, int toSign, int toExec) : _name(name), _toSign(toSign), _toExec(toExec), _isSigned(false)
{
    if (toSign < 1 || toExec < 1)
        throw (AForm::GradeTooHighException());
    else if (toSign > 150 || toExec > 150)
        throw (AForm::GradeTooLowException());
    else
        std::cout << "AForm parameterized constructor called with param_name: " << name << ". And param_GradeToExec: " << toExec << ". And also param_GradeToSign: " << toSign << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _toSign(other._toSign), _toExec(other._toExec), _isSigned(other._isSigned) 
{ 
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{ 
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this; 
}

AForm::~AForm(void)
{
    std::cout << "AForm destructor called" << std::endl; 
}

const std::string  AForm::getName() const
{
    return this->_name;
}

int AForm::getToSign() const
{
    return this->_toSign;
}

int AForm::getToExec() const
{
    return this->_toExec;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "his rank is to high !";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "his rank is to low !";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "his form is not signed !";
}

std::ostream& operator<<(std::ostream& ostr, AForm const& obj)
{
    std::string sign;
    if (obj.getIsSigned() == false)
        sign = " is not signed !";
    else if (obj.getIsSigned() == true)
        sign = " is signed !";
    ostr << "AForm: " << obj.getName() << " can be sign by grade: " << obj.getToSign() << " and exec by grade: " << obj.getToExec() << sign;
    return ostr;
}
