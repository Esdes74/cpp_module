/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:38:45 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/24 19:36:48 by eslamber         ###   ########.fr       */
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
	test.beRepaired(3);
	delete broint;
	return (0);
}
