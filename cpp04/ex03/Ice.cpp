/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:19:58 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/21 11:59:36 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) 
{ 
    std::cout << "Ice default constructor called" << std::endl;
    this->_type = "ice";
}

Ice::Ice(const Ice& other) 
{ 
    std::cout << "Ice copy constructor called" << std::endl; 
    *this = other; 
}

Ice& Ice::operator=(const Ice& other)
{ 
    std::cout << "Ice assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    } 
    return *this; 
}

Ice::~Ice(void)
{
    std::cout << "Ice destructor called" << std::endl; 
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Ice::clone(void) const
{
    Ice* retour = new Ice;
    return retour;
}

