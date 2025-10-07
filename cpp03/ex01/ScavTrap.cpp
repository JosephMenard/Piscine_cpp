/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:04:02 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/18 15:37:05 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : Claptrap()
{
    std::cout << "ScavTrap was created with No Name" << std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    this->is_guard = false;
}

ScavTrap::ScavTrap(std::string name) : Claptrap(name)
{
    std::cout << "ScavTrap was created with name " << name << std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    this->is_guard = false;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->name << " was destructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : Claptrap(other)
{
    std::cout << "ScavTrap copy constructor was called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignement operator called" << std::endl;
    if (this != &other)
        Claptrap::operator=(other);
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energy_points > 0 && this->hit_points > 0)
    {
       std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage !" << std::endl;
       this->energy_points--;
    }
    else if (this->hit_points == 0)
        std::cout << "ScavTrap " << this->name << " can't attack, he's dead" << std::endl;
    else
        std::cout << "ScavTrap " << this->name << " has no more energy points and can't attack" << std::endl;
}

void ScavTrap::guardGate(void)
{
    if (this->is_guard == false)
    {
        std::cout << "ScavTrap " << this->name << " put guard ON" << std::endl;
        this->is_guard = true;
    }
    else if (this->is_guard == true)
    {
        std::cout << "ScavTrap " << this->name << " put guard OFF" << std::endl;
        this->is_guard = false;
    }
}

void ScavTrap::print_scavtrap(void)
{
    std::cout << "ScavTrap: Name: " << this->name << std::endl;
    std::cout << "ScavTrap: Hit point: " << this->hit_points<< std::endl;
    std::cout << "ScavTrap: Energy points: " << this->energy_points << std::endl;
    std::cout << "ScavTrap: Attack damage: " << this->attack_damage << std::endl;
    std::cout << "ScavTrap: Is guard ?: " << this->is_guard << std::endl;
}

