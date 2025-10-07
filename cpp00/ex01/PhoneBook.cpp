/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:46:30 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/14 11:20:01 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"


PhoneBook::PhoneBook() : index(0), current_size(0) {}

void PhoneBook::add_contact(const Contact &contact)
{
    contacts_list[current_size] = contact;
    current_size = (current_size + 1) % 8;
    if (index < 8)
        index++;
}

void PhoneBook::show_contacts() const
{
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    for (int i = 0; i < index; i++)
    {
        std::cout << "         " << i + 1 << "|";
        contacts_list[i].display_contact();
    }
}

