/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:55:30 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/18 09:57:12 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(string type)
{
	this->type = type;
}

void	Weapon::setType(string type)
{
	this->type = type;
}

string	Weapon::getType()
{
	return (this->type);
}
