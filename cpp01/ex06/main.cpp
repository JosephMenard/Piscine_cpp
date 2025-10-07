/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:50:54 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/14 19:04:28 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void harl_filter(std::string cmd, Harl &le_H)
{
    std::string level[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int index = 0;
    int i = 0;

    while (i < 4)
    {
        if (cmd == level[i])
        {
            index = i;
            break;
        }
        i++;
    }
    if (i == 4)
        index = -1;
    switch (index)
    {
        case 0:
            le_H.complain("DEBUG");
        case 1:
            le_H.complain("INFO");
        case 2:
            le_H.complain("WARNING");
        case 3:
            le_H.complain("ERROR");   
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }  
    
}

int main(void)
{
    std::string cmd;
    
    while (1)
    {
        std::cout << "Harl ; ";
        std::getline(std::cin, cmd);
        Harl le_H;
        if (cmd == "exit")
            break;
        harl_filter(cmd, le_H);
    }
    return (0);
    
}