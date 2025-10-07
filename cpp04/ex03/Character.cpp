/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:54:04 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/21 12:24:14 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("Gilbert")
{ 
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_materia[i] = 0;
}

Character::Character(std::string param) : _name(param)
{
    std::cout << "Character parameterized constructor called with name: " << param << std::endl; 
    for (int i = 0; i < 4; i++)
        this->_materia[i] = 0;
}

Character::Character(const Character& other) 
{ 
    std::cout << "Character copy constructor called" << std::endl;
    this->_name = other._name;
    for (int i = 0; i < 4; i++)
        {
            if (other._materia[i])
            this->_materia[i] = other._materia[i]->clone();
        }
}

Character& Character::operator=(const Character& other)
{ 
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (this->_materia[i])
                delete this->_materia[i];
            if (other._materia[i])
            this->_materia[i] = other._materia[i]->clone();
        }
    } 
    return *this; 
}

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i])
            delete this->_materia[i];
    }
}

std::string const& Character::getName(void) const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    int j = 0;
    if (!m)
    {
        std::cout << "Materia gived in param do not exist" << std::endl;
        return ;
    }
    for (int i = 0; this->_materia[i] == 0; i++)
        j++;
    if (j >= 4)
    {
        std::cout << "Inventory is full can't equip another materia !" << std::endl;
        return ;
    }
    this->_materia[j] = m;
    std::cout << "Materia " << m->getType() << " has been equiped int the " << j - 1 << "th slot" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Wrong index, can't unequip materia" << std::endl;
        return ;
    }
    if (this->_materia[idx] == 0)
    {
        std::cout << "No materia at this slot, can't unequip materia" << std::endl;
        return ;
    }
    std::cout << "Materia " << this->_materia[idx]->getType() << " at slot " << idx << "has been unequiped !" << std::endl;
    this->_materia[idx] == 0;
}
void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3 || this->_materia[idx] == 0)
    {
        std::cout << "No materia in this adress" << std::endl;
        return ;
    }
    this->_materia[idx]->use(target);
}

