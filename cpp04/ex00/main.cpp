/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:47:41 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/19 12:40:13 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void )
{
    std::cout << "\nConstructor of good animal:"<< std::endl;
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\nGood animal's life:"<< std::endl;
	std::cout << "Dog->getType [" << dog->getType() << "] " << std::endl;
	std::cout << "Cat->getType [" << cat->getType() << "] " << std::endl;
    std::cout << "Animal->getType [" << animal->getType() << "] " << std::endl;
	cat->makeSound(); //will output the cat sound
	dog->makeSound(); //will output the dog sound
	animal->makeSound(); //will output the animal sound

	std::cout << "\nConstructor of wrong animal:"<< std::endl;
	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << "\nWrong animal's life:"<< std::endl;
	wrong_cat->makeSound(); //will output the animal sound
	wrong_animal->makeSound(); //will output the animal sound
    std::cout << "WrongCat->getType [" << wrong_cat->getType() << "] " << std::endl;
    std::cout << "WrongAnimal->getType [" << wrong_animal->getType() << "] " << std::endl;

	std::cout << "\nAll destructor:"<< std::endl;
	delete animal;
	delete dog;
	delete cat;
	delete wrong_cat;
	delete wrong_animal;
}