/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:34:38 by jmenard           #+#    #+#             */
/*   Updated: 2025/01/03 12:16:37 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

class PhoneBook 
{
    
    public:
        Contact contacts_list[8];
        int     index;
        int     current_size;
    
    public:
        PhoneBook();
        void add_contact(const Contact &contact);
        void search_contact() const;
        void show_contacts() const;
};

#endif