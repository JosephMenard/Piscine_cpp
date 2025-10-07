/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:21:21 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/21 12:32:41 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "inc.h"

class Cure : virtual public AMateria
{
    public:
        Cure(void);
        Cure(const Cure& other);
        Cure& operator=(const Cure& other);
        ~Cure(void);

        AMateria* clone() const;

};

#endif // CURE_HPP
