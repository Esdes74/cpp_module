/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:38:45 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/26 15:31:06 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	*broint = new ClapTrap;
	ClapTrap	*charle = new ClapTrap;

	broint->setNom("Broint");
	charle->setNom("Charle");
	broint->setHIT(5);
	broint->attack("Charle");
	charle->takeDamage(broint->HIT());
	charle->beRepaired(3);
	charle->takeDamage(broint->getHIT());
	charle->takeDamage(broint->getHIT());
	delete broint;
	return (0);
}
