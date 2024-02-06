/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:21:42 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 13:31:39 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

Scavtrap::Scavtrap()
{
	std::cout << "Constructeur par défaut Scavtrap appelé\n";
	nom = "defaut";
	pv = 100;
	pe = 50;
	hit = 20;
}

Scavtrap::Scavtrap(const std::string &name)
{
	std::cout << "Constructeur par nom Scavtrap appelé\n";
	nom = name;
	pv = 100;
	pe = 50;
	hit = 20;
}

Scavtrap::Scavtrap(const Scavtrap &cpy) : Claptrap(cpy)
{
	std::cout << "Scavtrap: " << nom << "appel du contructeur par copie\n";
	*this = cpy;
}

void	Scavtrap::attack(const std::string &target)
{
	if (pe > 0)
	{
		std::cout << "Le Scavtrap ";
		std::cout << nom << " attaque " << target << " et lui fait " << hit;
		std::cout << " dégats\n";
		pe--;
	}
	else
		std::cout << "Le Scavtrap " <<  nom << " n'a pas assez d'énergie pour attaquer\n";
}


void	Scavtrap::guardGate()
{
	std::cout << "Scavtrap: " << nom << " passe en mode gate keeper\n";
}

Scavtrap::~Scavtrap()
{
	std::cout << "Destructor Scavtrap appelé\n";
}
