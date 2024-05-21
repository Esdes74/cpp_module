/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:38:45 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/21 13:05:11 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	*broint = new ScavTrap;
	ClapTrap	*charle = new ClapTrap;
	ScavTrap	test("test");

	broint->setNom("Broint");
	charle->setNom("Charle");
	broint->attack("Charle");
	charle->takeDamage(broint->getHIT());
	charle->beRepaired(3);
	charle->takeDamage(broint->getHIT());
	charle->takeDamage(broint->getHIT());
	broint->takeDamage(broint->getHIT());
	test = *broint;
	test.beRepaired(3);
	broint->guardGate();
	delete broint;
	delete charle;
	return (0);
}
