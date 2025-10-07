/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:54:02 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/21 11:32:02 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "inc.h"

class AMateria;

class Character : virtual public ICharacter
{
    private:
        std::string _name;
        AMateria* _materia[4];

    public:
        Character(void);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character(void);
        Character(std::string param);
        
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        std::string const& getName() const;
};

#endif
