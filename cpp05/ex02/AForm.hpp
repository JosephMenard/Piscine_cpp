#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string  _name;
        const int  _toSign;
        const int  _toExec;
        bool _isSigned;

    public:
        AForm(void);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm(void);
        AForm(std::string const& name, int toSign, int toExec);

        void beSigned(Bureaucrat& obj);
        const std::string getName() const;
        int getToSign() const;
        int getToExec() const;
        bool getIsSigned() const;
        virtual void execute(Bureaucrat const & executor) const = 0;

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
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& ostr, AForm const& obj);

#endif
