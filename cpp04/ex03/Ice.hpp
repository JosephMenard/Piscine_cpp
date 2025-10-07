/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:21:23 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/21 11:59:46 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : virtual public AMateria
{
    public:
        Ice(void);
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        ~Ice(void);

        AMateria* clone() const;
};

#endif // ICE_HPP
