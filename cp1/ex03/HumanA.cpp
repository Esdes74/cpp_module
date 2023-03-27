/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:04:40 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/18 10:19:48 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(string name, Weapon &weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

void	HumanA::attack()
{
	cout << this->name << " attacks with their " << this->weapon->getType() << \
		endl;
}
