/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:56:08 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/13 14:03:12 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int i = 0;
    int N = 5;
    Zombie* horde = zombieHorde(N, "jmenard");
    while (i < N)
    {
        horde[i].announce();
        i++;
    }
    delete [] horde;
    return (0); 
}