/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:08:22 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/21 11:22:54 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("fer")
{
    std::cout << "AMateria default constrcutor has been called" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type)
{
    std::cout << "AMateria constrcutor has been called with type " << this->_type << std::endl;
}

AMateria::~AMateria() 
{
    std::cout << "AMateria destrcutor has been called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    std::cout << "AMateria copy constrcutor has been called" << std::endl;
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        this->_type = other._type;
    return *this;
}

std::string const& AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "Unknow material is use to " << target.getName() << std::endl;
}
