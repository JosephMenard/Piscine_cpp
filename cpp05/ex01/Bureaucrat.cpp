#include "Bureaucrat.hpp"

void Bureaucrat::signForm(Form& obj)
{
    try
    {
        obj.beSigned(*this);
        std::cout << "Bureaucrat: " << this->_name << " signed " << obj.getName() << std::endl;
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cout << "Bureaucrat: " << this->_name << " couldn't sign " << obj.getName() << " because " << e.what() << std::endl;
    }
    
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Error: Grade is too high, Bureaucrat can't be better than first !";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Error: Grade is too low, he can't be bellow 150th !";
}

Bureaucrat::Bureaucrat(void) : _name("no name"), _grade(150)
{ 
    std::cout << "Bureaucrat default constructor called" << std::endl; 
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else
    {
        std::cout << "Bureaucrat parameterized constructor called with param_name: " << name << ". And param_grade: " << grade << std::endl; 
        this->_grade = grade;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{ 
    std::cout << "Bureaucrat copy constructor called" << std::endl; 
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{ 
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &other)
        this->_grade = other._grade;
    return *this; 
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called for: " << this->_name << std::endl; 
}

const std::string Bureaucrat::getName(void) const
{
    return this->_name;
}

int Bureaucrat::getGrade(void) const 
{
    return this->_grade;
}

void Bureaucrat::promotion(void)
{
    if (this->_grade <= 1)
        throw (Bureaucrat::GradeTooHighException());
    this->_grade--;
    std::cout << this->_name << " has been promoted ! he's now at grade: " << this->_grade << std::endl;
}

void Bureaucrat::demotion(void)
{
    if (this->_grade >= 150)
        throw (Bureaucrat::GradeTooLowException());
    this->_grade++;
    std::cout << this->_name << " has been demoted ! he's now at grade: " << this->_grade << std::endl;
}

std::ostream& operator<<(std::ostream& ostr, Bureaucrat const& obj)
{
    ostr << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return ostr;
}