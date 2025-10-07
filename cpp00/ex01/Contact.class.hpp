/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:24:29 by jmenard           #+#    #+#             */
/*   Updated: 2025/01/04 00:09:56 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;
    
    public:
        Contact();
        void set_contact(const std::string &first_name, const std::string &last_name, const std::string &nick_name, const std::string &phone_number, const std::string &darkest_secret);
        void display_contact() const;
        void show_one() const;
};

#endif