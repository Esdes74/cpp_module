/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:40:10 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/17 14:31:31 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*Xavier;
	int		nb(10);

	Xavier = zombieHorde(nb, "Steve");
	do
		Xavier[nb - 1].announce();
	while ((nb--) - 1 > 0);
	delete[] Xavier;
	return (0);
}
