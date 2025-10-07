/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:05:22 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/21 12:34:23 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "inc.h"

class ICharacter;

class AMateria 
{
    protected:
        std::string  _type;
    
    public:
        AMateria();
        ~AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        
};

#endif // AMATERIA_H
