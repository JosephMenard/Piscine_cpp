/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:30:55 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/17 16:33:59 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(const int nbr)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixe = nbr << bits;
}

Fixed::Fixed(const float nbr)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixe = (int)roundf(nbr * (1 << bits));
}

Fixed::Fixed(void) : fixe(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixe = other.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->fixe);
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->fixe = raw;
}

float Fixed::toFloat(void) const
{
    // std::cout << "toFloat member function called" << std::endl;
    return ((float)this->fixe / (float)(1 << Fixed::bits));
}

int Fixed::toInt(void) const 
{
    // std::cout << "toInt member function called" << std::endl;
    return ((int)this->fixe >> Fixed::bits);
}

std::ostream& operator<<(std::ostream &ostr, Fixed const &Fixed)
{
    // std::cout << "Overload of operator << called" << std::endl;
    ostr << Fixed.toFloat();
    return (ostr);
}