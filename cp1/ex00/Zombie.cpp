/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:33:54 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/17 13:45:39 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(string name)
{
	this->name = name;
}

void	Zombie::announce()
{
	cout << this->name << " : BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
	cout << this->name << " : *Dead... Finally*\n";
}
