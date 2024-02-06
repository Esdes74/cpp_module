/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.std::cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:33:54 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 12:01:58 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void	Zombie::announce()
{
	std::cout << this->name << " : BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
	std::cout << this->name << " : *Dead... Finally*\n";
}
