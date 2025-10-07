/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:47:26 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/19 12:02:31 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    this->_type = "Cat";
    std::cout << "Constructor Cat has been called" << std::endl;
}

Cat::~Cat(void)
{
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
    }
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "MIAOU MIAOU (it's a cat sound)" << std::endl;
}
