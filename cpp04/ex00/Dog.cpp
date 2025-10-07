/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:46:26 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/19 12:02:22 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    this->_type = "Dog";
    std::cout << "Constructor Dog has been called" << std::endl;
}

Dog::~Dog(void)
{
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
    }
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "WOUAF WOUAF (it's a dog sound)" << std::endl;
}
