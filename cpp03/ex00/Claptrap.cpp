/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:20:05 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/18 15:01:31 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

Claptrap::Claptrap(void) : hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "Claptrap was created with No Name" << std::endl;
    this->name = "No Name"; 
}
Claptrap::~Claptrap(void)
{
    std::cout << "Claptrap " << this->name << " was destructed" << std::endl;
}

Claptrap::Claptrap(std::string name) : hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "Claptrap was created with name " << name << std::endl;
    this->name = name;
}

Claptrap::Claptrap(Claptrap const &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Claptrap& Claptrap::operator=(const Claptrap& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

void Claptrap::attack(const std::string& target)
{
    if (this->energy_points > 0 && this->hit_points > 0)
    {
       std::cout << "Claptrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage !" << std::endl;
       this->energy_points--;
    }
    else if (this->hit_points == 0)
        std::cout << "Claptrap " << this->name << " can't attack, he's dead" << std::endl;
    else
        std::cout << "Claptrap " << this->name << " has no more energy points and can't attack" << std::endl;
}

void Claptrap::takeDamage(unsigned int amount)
{
    if (this->hit_points > 0)
    {
       std::cout << "Claptrap " << this->name << " take " << amount << " point of damage" << std::endl;
       this->hit_points -= amount;
    }
    if (this->hit_points <= 0)
    {
        std::cout << "Claptrap " << this->name << " is dead" << std::endl;
        this->hit_points = 0;
    }
}

void Claptrap::beRepaired(unsigned int amount)
{
    if (this->energy_points > 0 && this->hit_points > 0)
    {
       std::cout << "Claptrap " << this->name << " repair himself and gain " << amount << " hit_point " << std::endl;
       this->energy_points--;
       this->hit_points += amount;
    }
    else if (this->hit_points == 0)
        std::cout << "Claptrap " << this->name << " can't repair himself, he's dead" << std::endl;
    else
        std::cout << "Claptrap " << this->name << " has no more energy points and can't repair himself" << std::endl;
}

void Claptrap::print_claptrap(void)
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Hit point: " << this->hit_points<< std::endl;
    std::cout << "Energy points: " << this->energy_points << std::endl;
    std::cout << "Attack damage: " << this->attack_damage << std::endl;
}