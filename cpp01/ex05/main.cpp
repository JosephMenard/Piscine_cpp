/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:50:54 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/14 17:58:09 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

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
        le_H.complain(cmd);
    }
    return (0);
    
}