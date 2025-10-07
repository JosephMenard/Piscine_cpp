/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:24:37 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/14 11:21:17 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>

std::string nbr_to_string (int nbr_format)
{
    std::stringstream str_format;
    str_format << nbr_format;
    return str_format.str();
}

Contact::Contact() {}

void Contact::set_contact(const std::string &first, const std::string &last, const std::string &nick, const std::string &phone, const std::string &secret)
{
    first_name = first;
    last_name = last;
    nick_name = nick;
    phone_number = phone;
    darkest_secret = secret;
}

std::string troncate_str(std::string str)
{
    if (str.length() > 10)
    {
        str = str.substr(0, 9);
        str += ".";
    }
    return (str);
}

void Contact::show_one(void) const
{
    std::cout << "First name : " << first_name << std::endl;
    std::cout << "Last name : " << last_name << std::endl;
    std::cout << "Nick name : " << nick_name << std::endl;
    std::cout << "Phone number : " << phone_number << std::endl;
    std::cout << "Darkest secret : " << darkest_secret << std::endl;
}

void Contact::display_contact(void) const
{
    std::cout << std::setw(10) << troncate_str(first_name) << "|";
    std::cout << std::setw(10) << troncate_str(last_name) << "|";
    std::cout << std::setw(10) << troncate_str(nick_name) << std::endl;
}

