/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:26:37 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/19 12:26:39 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    this->_type = "WrongCat";
    std::cout << "Constructor WrongCat has been called" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "Destructor WrongCat has been called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
    std::cout << "Copy constructor has been called for class WrongCat" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "Overload of operator has been called for class WrongCat" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

void WrongCat::makeSound(void) const
{
    std::cout << "MIAOU MIAOU (it's a WrongCat sound)" << std::endl;
}