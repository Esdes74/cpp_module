/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:21:42 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/28 15:04:51 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

Scavtrap::Scavtrap()
{
	cout << "Constructeur par défaut Scavtrap appelé\n";
	nom = "defaut";
	pv = 100;
	pe = 50;
	hit = 20;
}

Scavtrap::Scavtrap(const string &name)
{
	cout << "Constructeur par nom Scavtrap appelé\n";
	nom = name;
	pv = 100;
	pe = 50;
	hit = 20;
}

Scavtrap::Scavtrap(const Scavtrap &cpy) : Claptrap(cpy)
{
	cout << "Scavtrap: " << nom << "appel du contructeur par copie\n";
	*this = cpy;
}

void	Scavtrap::attack(const string &target)
{
	if (pe > 0)
	{
		cout << "Le Scavtrap ";
		cout << nom << " attaque " << target << " et lui fait " << hit;
		cout << " dégats\n";
		pe--;
	}
	else
		cout << "Le Scavtrap " <<  nom << " n'a pas assez d'énergie pour attaquer\n";
}


void	Scavtrap::guardGate()
{
	cout << "Scavtrap: " << nom << " passe en mode gate keeper\n";
}

Scavtrap::~Scavtrap()
{
	cout << "Destructor Scavtrap appelé\n";
}
