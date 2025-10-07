/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:24:39 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/18 16:34:27 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "\nConstructor: " << std::endl;
    FragTrap eustache("eustache");
    ScavTrap david("david");
    Claptrap eric("eric");
    
    std::cout << "\nEustache's life: " << std::endl;
    eustache.attack("les ops");
    eustache.beRepaired(10);
    eustache.takeDamage(100);
    eustache.attack("les ops");
    eustache.beRepaired(10);
    eustache.highFivesGuys();
    eustache.print_fragtrap();

    
    std::cout << "\nDavid's life: " << std::endl;
    david.attack("les ops");
    david.beRepaired(10);
    david.takeDamage(100);
    david.attack("les ops");
    david.beRepaired(10);
    david.guardGate();
    david.print_scavtrap();

    std::cout << "\nEric's life: " << std::endl;
    eric.attack("les ops");
    eric.beRepaired(4);
    eric.takeDamage(15);
    eric.attack("les ops");
    eric.beRepaired(4);
    eric.print_claptrap();
    std::cout << "\nDestructor: " << std::endl;
    return 0;
}