/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:17:29 by jmenard           #+#    #+#             */
/*   Updated: 2025/01/04 00:17:50 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <string>
#include <cctype>

std::string parse_str(std::string str)
{
    std::string result;
    bool in_space = false;

    for (int i = 0; i < (int)str.length(); i++)
    {
        if (std::isspace(str[i]) && in_space == false)
        {
            in_space = true;
            result += ' ';
        }
        else if (!std::isspace(str[i]))
        {
            in_space = false;
            result += str[i];
        }
    }
    return (result);
}

int check_phone_number(std::string phone_number)
{
    int i;
    
    for (i = 0; i < (int)phone_number.length(); i++)
    {
        if (!std::isdigit(phone_number[i]))
            return (1);
    }
    if (i != 10)
        return (1);
    return (0);
}   

int verif_entry(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret)
{
    if (first_name.empty() || last_name.empty() || nick_name.empty() || phone_number.empty() || darkest_secret.empty())
        return (0);
    if (first_name == " " || last_name == " " || nick_name == " " || phone_number == " " || darkest_secret == " ")
        return (0);
    return (1);
}

int add_contact(PhoneBook& phone_book)
{
    Contact contact;
    std::string first_name, last_name, nick_name, phone_number, darkest_secret;
    
    std::cout << "Entrez le prenom: ";
    std::getline(std::cin, first_name);
    first_name = parse_str(first_name);
    
    std::cout << "Entrez le nom: ";
    std::getline(std::cin, last_name);
    last_name = parse_str(last_name);

    std::cout << "Entrez le surnom: ";
    std::getline(std::cin, nick_name);
    nick_name = parse_str(nick_name);

    std::cout << "Entrez le telephone: ";
    std::getline(std::cin, phone_number);
    while (1)
    {
        if (check_phone_number(phone_number) == 0)
            break ;
        else
        {
            std::cout << "Numero de telephone invalide, veuillez reessayer" << std::endl;
            std::cout << "Entrez le telephone: ";
            std::getline(std::cin, phone_number);
        }
    }

    std::cout << "Entrez le secret le plus sombre: ";
    std::getline(std::cin, darkest_secret);
    darkest_secret = parse_str(darkest_secret);
    
    if (verif_entry(first_name, last_name, nick_name, phone_number, darkest_secret) == 1)
    {
        contact.set_contact(first_name, last_name, nick_name, phone_number, darkest_secret);
        phone_book.add_contact(contact);
    }
    else
    {
        std::cout << "Veuillez remplir tous les champs" << std::endl;
        add_contact(phone_book);   
    }
    return (0);
}

int search_contact(PhoneBook& phone_book)
{
    int index;
    std::string index_str;

    phone_book.show_contacts();
    std::cout << "Entrez l'index du contact que vous voulez voir : ";
    std::getline(std::cin, index_str);
    if (index_str.length() != 1 || !std::isdigit(index_str[0]) || index_str[0] < '1' || index_str[0] > '8')
    {
        std::cout << "Index invalide, veuillez ressayer" << std::endl;
        return (1);
    }
    index = index_str[0] - '0';
    if (index > phone_book.index)
    {
        std::cout << "Index invalide, veuillez ressayer" << std::endl;
        return (1);
    }
    phone_book.contacts_list[index - 1].show_one();
    return (0); 
}

int main()
{
    PhoneBook phone_book;
    Contact contact;
    std::string cmd;

    while (1)
    {
        std::cout << "Entrez votre commande : ";
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
        {
            int add_return = add_contact(phone_book);
            if (add_return != 0)
                return (1);
        }
        else if (cmd == "SEARCH")
        {
            int search_return = search_contact(phone_book);
            while (search_return == 1)
                search_return = search_contact(phone_book);
            if (search_return != 0)
                return (1);
        }
        else if (cmd == "EXIT")
            break ;
        else
        {
            std::cout << "Commande invalide, commandes valide ;" << std::endl;
            std::cout << "ADD, SEARCH, EXIT" << std::endl;    
        }
    }
}