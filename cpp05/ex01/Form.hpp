#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string  _name;
        const int  _toSign;
        const int  _toExec;
        bool _isSigned;

    public:
        Form(void);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form(void);
        Form(std::string const& name, int toSign, int toExec);

        void beSigned(Bureaucrat& obj);
        const std::string  getName() const;
        int getToSign() const;
        int getToExec() const;
        bool getIsSigned() const;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& ostr, Form const& obj);

#endif
