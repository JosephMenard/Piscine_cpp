/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:09:00 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/13 13:52:15 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;
    
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie();
        void announce();
        void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif