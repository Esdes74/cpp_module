/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:08:41 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/17 14:17:50 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, string name)
{
	Zombie	*horde;
	int		i(0);

	horde = new Zombie[n];
	while (i < n)
		horde[i++].setName(name);
	return (horde);
}
