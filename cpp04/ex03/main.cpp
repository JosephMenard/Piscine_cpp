/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:47:41 by jmenard           #+#    #+#             */
/*   Updated: 2025/03/21 12:32:18 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

int main(void)
{
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	ICharacter* gilbert = new Character();
	ICharacter* francois = new Character("francois");

	gilbert->equip(ice);
	gilbert->equip(cure);

	gilbert->use(0, *francois);
	gilbert->use(1, *francois);

	gilbert->unequip(1);
	gilbert->use(1, *francois);
	
	delete ice;
	delete cure;
	delete gilbert;
	delete francois;
}