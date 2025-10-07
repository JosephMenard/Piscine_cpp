/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:21:16 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/21 11:59:05 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) 
{ 
    std::cout << "Cure default constructor called" << std::endl;
    this->_type = "cure";
}

Cure::Cure(const Cure& other) 
{ 
    std::cout << "Cure copy constructor called" << std::endl; 
    *this = other; 
}

Cure& Cure::operator=(const Cure& other)
{ 
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    } 
    return *this; 
}

Cure::~Cure(void)
{
    std::cout << "Cure destructor called" << std::endl; 
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Cure::clone(void) const
{
    Cure* retour = new Cure;
    return retour;
}



