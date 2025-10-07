/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:18:06 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/14 16:19:51 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string ft_replace(std::string line, char **av)
{
    int         i  = 0;
    size_t      is_find = 0;
    std::string s1 = av[2];
    std::string s2 = av[3];

    while ((is_find = line.find(s1, i)) != std::string::npos)
    {
        line.erase(is_find, s1.size());
        line.insert(is_find, s2);
        i = is_find + s2.size();
    }
    
    return (line);
}

int main(int ac, char **av)
{
    std::string     buffer;
    std::string     line;
    std::ifstream   input_file;
    std::ofstream   output_file;
    
    
    if (ac != 4)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        return (1);
    }
    input_file.open(av[1]);
    if (input_file.fail())
    {
        std::cerr << "cannot open file : " << av[1] << std::endl;
        return (1);
    }
    while (std::getline(input_file, buffer))
        line += (buffer + '\n');
    input_file.close();
    output_file.open((std::string(av[1]) + ".replace").c_str());
    output_file << ft_replace(line, av);
    return (0);
}