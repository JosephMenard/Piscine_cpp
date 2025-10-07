/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:24:39 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/18 15:03:26 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

int main(void)
{
    Claptrap david("david");
    Claptrap no_name;
    
    david.attack("les ops");
    david.beRepaired(10);
    david.takeDamage(10);
    david.attack("les ops");
    david.beRepaired(10);
    david.print_claptrap();
    
    std::cout << "\n" << std::endl;
    
    no_name.attack("les ops");
    no_name.beRepaired(4);
    no_name.takeDamage(15);
    no_name.attack("les ops");//ne peut pas attaquer car mort
    no_name.beRepaired(4);//ne peut pas attaquer car mort
    no_name.print_claptrap();
    return 0;
}