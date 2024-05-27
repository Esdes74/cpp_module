/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:32:06 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/21 13:28:18 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default constructor FragTrap called\n";
	nom = "noname";
	pv = 100;
	pe = 100;
	hit = 30;
}

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "Name FragTrap constructor called\n";
	nom = name;
	pv = 100;
	pe = 100;
	hit = 30;
}

FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy)
{
	std::cout << "FragTrap: " << nom << "copy constructor called\n";
	*this = cpy;
}

// Surcharge d'opérateur
FragTrap	&FragTrap::operator=(const FragTrap &trap)
{
	std::cout << nom << ": FragTrap copy assignment operator called\n";
	if (this != &trap)
		ClapTrap::operator=(trap);
	return (*this);
}

void	FragTrap::highFivesGuys() const
{
	std::cout << "FragTrap: " << nom << " give me five guy\n";
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap Called\n";
}
