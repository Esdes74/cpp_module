/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:38:45 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/21 13:14:23 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	*broint = new ClapTrap;
	ClapTrap	*charle = new ClapTrap;
	ClapTrap	test("test");

	broint->setNom("Broint");
	charle->setNom("Charle");
	test = *charle;
	broint->setHIT(5);
	broint->attack("Charle");
	charle->takeDamage(broint->HIT());
	charle->beRepaired(3);
	charle->takeDamage(broint->getHIT());
	charle->takeDamage(broint->getHIT());
	charle->takeDamage(8);
	charle->takeDamage(3);
	charle->beRepaired(3);
	delete charle;
	test.beRepaired(3);
	test.takeDamage(14);
	delete broint;
	return (0);
}
