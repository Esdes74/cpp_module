/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:32:06 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/26 16:43:59 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Constructeur par défaut FragTrap appelé\n";
	nom = "defaut";
	pv = 100;
	pe = 100;
	hit = 30;
}

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "Constructeur par nom FragTrap appelé\n";
	nom = name;
	pv = 100;
	pe = 100;
	hit = 30;
}

FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy)
{
	std::cout << "FragTrap: " << nom << "appel du contructeur par copie\n";
	*this = cpy;
}

// Surcharge d'opérateur
FragTrap	&FragTrap::operator=(const FragTrap &trap)
{
	std::cout << nom << ": Surcharge d'opérateur d'affectation FragTrap appelé\n";
	if (this != &trap)
	{
		*this = trap;
	}
	return (*this);
}

void	FragTrap::highFivesGuys() const
{
	std::cout << "FragTrap: " << nom << " tape m'en 5 s'il te plait\n";
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap appelé\n";
}
