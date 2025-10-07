/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:47:41 by jmenard           #+#    #+#             */
/*   Updated: 2025/05/29 15:09:45 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	int nbr = 4;
	const Animal *(horde[nbr]);
	 //Animal a;
	
	std::cout << "\n||| Constructor for Cat and Dog |||" << std::endl;
	for (int i = 0; i < nbr; i++)
	{
		if (i < (nbr / 2))
			horde[i] = new Dog();
		else if (i >= (nbr / 2))
			horde[i] = new Cat();
	}
	std::cout << "\n||| Destructor for Cat and Dog |||" << std::endl;
	for (int i = 0; i < nbr; i++)
		delete horde[i];

	std::cout << "\n||| Test of the subject |||" << std::endl;
	std::cout << "Constructor :" << std::endl;
	Animal* j = new Dog();
	Animal* i = new Cat();
	
	j->makeSound();
	i->makeSound();
	
	std::cout << "Destructor :" << std::endl;
	delete j;
	delete i;
}