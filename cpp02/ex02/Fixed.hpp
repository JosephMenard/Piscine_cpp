/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:03:36 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/17 17:42:27 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 fixe;
        static const int    bits = 8;
        
    public:
        Fixed(const int nbr);
        Fixed(const float nbr);
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        Fixed operator+(Fixed const &other) const;
        Fixed operator-(Fixed const &other) const;
        Fixed operator*(Fixed const &other) const;
        Fixed operator/(Fixed const &other) const;
        
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
        
        bool operator>(Fixed const &other) const;
        bool operator<(Fixed const &other) const;
        bool operator>=(Fixed const &other) const;
        bool operator<=(Fixed const &other) const;
        bool operator==(Fixed const &other) const;
        bool operator!=(Fixed const &other) const;
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void) const;
        float toFloat(void) const;
        
        const static Fixed &max(Fixed const &nbr1, Fixed const &nbr2);
        const static Fixed &min(Fixed const &nbr1, Fixed const &nbr2);

    };

std::ostream& operator<<(std::ostream &ostr, Fixed const &Fixed);
Fixed const &min(Fixed const &nbr1, Fixed const &nbr2);
Fixed const &max(Fixed const &nbr1, Fixed const &nbr2);

#endif