/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:38:45 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/24 19:51:43 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ScavTrap	*broint = new ScavTrap;
	ClapTrap	*charle = new ClapTrap;
	FragTrap	alix("alix");
	FragTrap	este("este");

	broint->setNom("Broint");
	charle->setNom("Charle");
	broint->attack("Charle");
	este = alix;
	charle->takeDamage(broint->getHIT());
	charle->beRepaired(3);
	charle->takeDamage(broint->getHIT());
	charle->takeDamage(broint->getHIT());
	broint->takeDamage(broint->getHIT());
	alix.highFivesGuys();
	alix.beRepaired(50);
	este.beRepaired(50);
	delete broint;
	delete charle;
	return (0);
}
