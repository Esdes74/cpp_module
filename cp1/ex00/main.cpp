/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:40:10 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/17 13:54:55 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*Xavier;

	Xavier = newZombie("Xavier");
	Xavier->announce();

	randomChump("Charle");
	
	delete Xavier;
	return (0);
}
