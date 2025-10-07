/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:31:50 by jmenard           #+#    #+#             */
/*   Updated: 2024/12/17 14:22:25 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int     ft_toupper(int c)
{
        if (c >= 'a' && c <= 'z')
                return (c - 32);
        return (c);
}

char    *maj(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        str[i] = ft_toupper(str[i]);
        i++;
    }
    return (str);
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    if (ac <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {     
        while (i < ac)
        {
            std::cout << maj(av[i]);
            i++;
        }
    }
    std::cout << "" << std::endl;
    return (1);
}

