/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:14:39 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/20 14:19:39 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() 
{
    std::cout << "Brain has bean created" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Constructor copy has been called for Brain" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Copy assignement has been called for Brain" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain() 
{
    std::cout << "Brain has been destructed" << std::endl;
}

void Brain::setIdea(int index_ideas, const std::string& idea)
{
    //std::cout << "Idea: " << idea << " number: " << index_ideas << " has been haded in brain" << std::endl;
    this->_ideas[index_ideas] = idea;
}

std::string Brain::get_ideas(int index_ideas)
{
    return this->_ideas[index_ideas];
}

