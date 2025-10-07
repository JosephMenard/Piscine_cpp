#include "Internet.hpp"
#include "AForm.hpp"

int main(int ac, char **av)
{
    if (ac != 3)
    {
        std::cout << "Please enter at least and max one form to create and one target !" << std::endl;
        return 1;
    }
    
    AForm *createdForm;
    Internet web;

    createdForm = web.makeForm(av[1], av[2]);

    delete createdForm;
}