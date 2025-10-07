/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:46:26 by jmenard           #+#    #+#             */
/*   Updated: 2025/05/29 15:09:14 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    this->_type = "Dog";
    std::cout << "Constructor Dog has been called" << std::endl;
    this->_brain = new Brain();
    set_idea_dog();
}

Dog::~Dog(void)
{
    std::cout << this->_brain->get_ideas(0) << std::endl; 
    delete this->_brain;
    std::cout << "Destructor Dog has been called" << std::endl;
}

Dog::Dog(const Dog& other)
{
    std::cout << "Copy constructor has been called for class Dog" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Overload of operator has been called for class Dog" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*(other.getBrain()));
    }
    return *this;
}

Brain* Dog::getBrain(void) const
{
    return this->_brain;
}

void    Dog::set_idea_dog(void)
{
    for (int i = 0; i < 100; i++)
        this->_brain->setIdea(i, "Dog idea");
}

void Dog::makeSound(void) const
{
    std::cout << "WOUAF WOUAF (it's a dog sound)" << std::endl;
}
