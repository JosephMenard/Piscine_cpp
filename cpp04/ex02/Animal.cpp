/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:56:29 by jmenard           #+#    #+#             */
/*   Updated: 2025/05/29 15:19:01 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Some random animal")
{
    std::cout << "Constructor Animal has been called with no type" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Constructor Animal has been called with type " << this->_type << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Destructor Animal has been called for the " << this->_type << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Copy constructor has been called for class Animal" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Overload of operator has been called for class Animal" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

void Animal::makeSound(void) const
{
    std::cout << "Sound of an unknown animal" << std::endl;
}

std::string Animal::getType(void) const
{
    return this->_type;
}

std::string Animal::getIdea() const
{
    this->
}