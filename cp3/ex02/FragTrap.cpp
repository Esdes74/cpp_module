/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:32:06 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/28 16:44:45 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

Fragtrap::Fragtrap()
{
	cout << "Constructeur par défaut Fragtrap appelé\n";
	nom = "defaut";
	pv = 100;
	pe = 100;
	hit = 30;
}

Fragtrap::Fragtrap(const string &name)
{
	cout << "Constructeur par nom Fragtrap appelé\n";
	nom = name;
	pv = 100;
	pe = 100;
	hit = 30;
}

Fragtrap::Fragtrap(const Fragtrap &cpy) : Claptrap(cpy)
{
	cout << "Fragtrap: " << nom << "appel du contructeur par copie\n";
	*this = cpy;
}

void	Fragtrap::highFivesGuys()
{
	cout << "Fragtrap: " << nom << " tape m'en 5 s'il te plait\n";
}

Fragtrap::~Fragtrap()
{
	cout << "Destructor Fragtrap appelé\n";
}
