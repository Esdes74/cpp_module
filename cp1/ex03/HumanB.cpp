/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:24:35 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/18 10:33:41 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(string name)
{
	this->name = name;
	this->weapon = 0;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	if (this->weapon != 0)
		cout << this->name << " attacks with their " << this->weapon->getType()\
			<< endl;
	else
		cout << this->name << " attacks with nothing\n";
}
