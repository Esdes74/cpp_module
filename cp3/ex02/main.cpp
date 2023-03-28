/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:38:45 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/28 16:47:57 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	Scavtrap	*broint = new Scavtrap;
	Claptrap	*charle = new Claptrap;
	Fragtrap	alix("alix");

	broint->setNom("Broint");
	charle->setNom("Charle");
	broint->attack("Charle");
	charle->takeDamage(broint->getHIT());
	charle->beRepaired(3);
	charle->takeDamage(broint->getHIT());
	charle->takeDamage(broint->getHIT());
	broint->takeDamage(broint->getHIT());
	alix.highFivesGuys();
	alix.beRepaired(50);
	delete broint;
	delete charle;
	return (0);
}
