/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:47:26 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/20 14:18:50 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    this->_type = "Cat";
    std::cout << "Constructor Cat has been called" << std::endl;
    this->_brain = new Brain();
    set_idea_cat();
}

Cat::~Cat(void)
{
    //std::cout << this->_brain->get_ideas(0) << std::endl; 
    delete this->_brain;
    std::cout << "Destructor Cat has been called" << std::endl;
}

Cat::Cat(const Cat& other)
{
    std::cout << "Copy constructor has been called for class Cat" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Overload of operator has been called for class Cat" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*(other.getBrain()));
    }
    return *this;
}

Brain* Cat::getBrain(void) const
{
    return this->_brain;
}

void    Cat::set_idea_cat(void)
{
    for (int i = 0; i < 100; i++)
        this->_brain->setIdea(i, "Cat idea");
}

void Cat::makeSound(void) const
{
    std::cout << "MIAOU MIAOU (it's a cat sound)" << std::endl;
}
