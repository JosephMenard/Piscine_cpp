#include "Form.hpp"

void Form::beSigned(Bureaucrat& obj)
{
    if (obj.getGrade() > this->_toSign)
        throw (Form::GradeTooLowException());
    else if (this->_isSigned == true)
        std::cout << "Form: " << this->_name << " is already signed" << std::endl;
    else
    {
        std::cout << "Form: " << this->_name << " has be signed by: " << obj.getName() << std::endl;
        this->_isSigned = true;
    }
}

Form::Form(void) : _name("no name"), _toSign(150), _toExec(150), _isSigned(false)
{ 
    std::cout << "Form default constructor called" << std::endl; 
}

Form::Form(std::string const& name, int toSign, int toExec) : _name(name), _toSign(toSign), _toExec(toExec), _isSigned(false)
{
    if (toSign < 1 || toExec < 1)
        throw (Form::GradeTooHighException());
    else if (toSign > 150 || toExec > 150)
        throw (Form::GradeTooLowException());
    else
        std::cout << "Form parameterized constructor called with param_name: " << name << ". And param_GradeToExec: " << toExec << ". And also param_GradeToSign: " << toSign << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _toSign(other._toSign), _toExec(other._toExec), _isSigned(other._isSigned) 
{ 
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{ 
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this; 
}

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl; 
}

const std::string  Form::getName() const
{
    return this->_name;
}

int Form::getToSign() const
{
    return this->_toSign;
}

int Form::getToExec() const
{
    return this->_toExec;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Error: this rank is to high !";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Error: this rank is to low !";
}

std::ostream& operator<<(std::ostream& ostr, Form const& obj)
{
    std::string sign;
    if (obj.getIsSigned() == false)
        sign = " is not signed !";
    else if (obj.getIsSigned() == true)
        sign = " is signed !";
    ostr << "Form: " << obj.getName() << " can be sign by grade: " << obj.getToSign() << " and exec by grade: " << obj.getToExec() << sign;
    return ostr;
}
