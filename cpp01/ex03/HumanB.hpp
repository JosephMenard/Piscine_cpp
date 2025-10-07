/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:42:16 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/14 13:07:29 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;
        
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void setWeapon(Weapon &weapon);
        void attack(void);
};