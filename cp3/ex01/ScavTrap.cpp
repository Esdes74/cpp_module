/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:21:42 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/21 12:58:39 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap constructor called\n";
	nom = "noname";
	pv = 100;
	pe = 50;
	hit = 20;
}

ScavTrap::ScavTrap(const std::string &name)
{
	std::cout << "Name ScavTrap constructor called\n";
	nom = name;
	pv = 100;
	pe = 50;
	hit = 20;
}

ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy)
{
	std::cout << "ScavTrap: " << nom << "copy constructor called\n";
	*this = cpy;
}

// Surcharge d'opérateur
ScavTrap	&ScavTrap::operator=(const ScavTrap &trap)
{
	std::cout << nom << ": Scavtrap copy assignment operator called\n";
	if (this != &trap)
		ClapTrap::operator=(trap);
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (pe > 0)
	{
		std::cout << "ScavTrap ";
		std::cout << nom << " attack " << target << " and do him " << hit;
		std::cout << " damage\n";
		pe--;
	}
	else
		std::cout << "ScavTrap " <<  nom << " don't have enought energy to attack\n";
}

void	ScavTrap::guardGate() const
{
	std::cout << "ScavTrap: " << nom << " goes into gate keeper mode\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called\n";
}
