/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:32:06 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 13:33:25 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

Fragtrap::Fragtrap()
{
	std::cout << "Constructeur par défaut Fragtrap appelé\n";
	nom = "defaut";
	pv = 100;
	pe = 100;
	hit = 30;
}

Fragtrap::Fragtrap(const std::string &name)
{
	std::cout << "Constructeur par nom Fragtrap appelé\n";
	nom = name;
	pv = 100;
	pe = 100;
	hit = 30;
}

Fragtrap::Fragtrap(const Fragtrap &cpy) : Claptrap(cpy)
{
	std::cout << "Fragtrap: " << nom << "appel du contructeur par copie\n";
	*this = cpy;
}

void	Fragtrap::highFivesGuys()
{
	std::cout << "Fragtrap: " << nom << " tape m'en 5 s'il te plait\n";
}

Fragtrap::~Fragtrap()
{
	std::cout << "Destructor Fragtrap appelé\n";
}
