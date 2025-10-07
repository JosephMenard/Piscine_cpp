/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:53:42 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/18 16:17:55 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : Claptrap()
{
    std::cout << "FragTrap was created with No Name" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : Claptrap(name)
{
    std::cout << "FragTrap was created with name " << name << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->name << " was destructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : Claptrap(other)
{
    std::cout << "FragTrap copy constructor was called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap copy assignement operator called" << std::endl;
    if (this != &other)
        Claptrap::operator=(other);
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap did high five to the ops" << std::endl;
}

void FragTrap::print_fragtrap(void)
{
    std::cout << "FragTrap: Name: " << this->name << std::endl;
    std::cout << "FragTrap: Hit point: " << this->hit_points<< std::endl;
    std::cout << "FragTrap: Energy points: " << this->energy_points << std::endl;
    std::cout << "FragTrap: Attack damage: " << this->attack_damage << std::endl;
}