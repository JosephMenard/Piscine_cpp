/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:24:02 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/19 12:24:04 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("No Type")
{
    std::cout << "Constructor WrongAnimal has been called with no type" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "Constructor WrongAnimal has been called with type " << this->_type << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "Destructor WrongAnimal has been called for the " << this->_type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "Copy constructor has been called for class WrongAnimal" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "Overload of operator has been called for class WrongAnimal" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Sound of an unknown WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return this->_type;
}