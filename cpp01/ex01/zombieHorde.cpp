/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:23:02 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/13 14:03:46 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    int i = 0;

    if (N <= 0)
        return (NULL);
    Zombie* horde = new Zombie[N];
    if (!horde)
        return (NULL);
    while (i < N)
    {
        horde[i].setName(name);
        i++;
    }
    return (horde);
}