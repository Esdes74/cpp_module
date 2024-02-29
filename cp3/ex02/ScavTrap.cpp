/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:21:42 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/29 17:17:44 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Constructeur par défaut ScavTrap appelé\n";
	nom = "noname";
	pv = 100;
	pe = 50;
	hit = 20;
}

ScavTrap::ScavTrap(const std::string &name)
{
	std::cout << "Constructeur par nom ScavTrap appelé\n";
	nom = name;
	pv = 100;
	pe = 50;
	hit = 20;
}

ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy)
{
	std::cout << "ScavTrap: " << nom << "appel du contructeur par copie\n";
	*this = cpy;
}

// Surcharge d'opérateur
ScavTrap	&ScavTrap::operator=(const ScavTrap &trap)
{
	std::cout << nom << ": Surcharge d'opérateur d'affectation ScavTrap appelé\n";
	if (this != &trap)
	{
		*this = trap;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (pe > 0)
	{
		std::cout << "Le ScavTrap ";
		std::cout << nom << " attaque " << target << " et lui fait " << hit;
		std::cout << " dégats\n";
		pe--;
	}
	else
		std::cout << "Le ScavTrap " <<  nom << " n'a pas assez d'énergie pour attaquer\n";
}


void	ScavTrap::guardGate() const
{
	std::cout << "ScavTrap: " << nom << " passe en mode gate keeper\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap appelé\n";
}
