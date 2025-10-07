#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm(void);

        void execute(Bureaucrat const& obj) const;

};

#endif // ROBOTOMYREQUESTFORM_HPP
