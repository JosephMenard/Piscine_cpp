/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:19:21 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/13 13:49:54 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    this->name = "Zombie sans nom";
    std::cout << "Zombie " << this->name << " created !" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Zombie " << this->name << " created !" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " destroyed !" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}


