/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:56:08 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/13 13:51:46 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* zomb = newZombie("Jmenard");
    zomb->announce();
    delete zomb;
    randomChump("Mianni");
    return (0);
}