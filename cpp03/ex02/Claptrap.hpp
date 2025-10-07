/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:13:46 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/18 15:10:41 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class Claptrap
{
    protected:
        std::string name;
        int hit_points;
        int energy_points;
        int attack_damage;

    public:
        Claptrap(void);
        Claptrap(std::string name);
        Claptrap(const Claptrap& other);
        Claptrap& operator=(const Claptrap& other);
        ~Claptrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void print_claptrap(void);
};

#endif