/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:39:03 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 12:04:27 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		// Constructeur
		Zombie(std::string name = "");

		// Fonction membre
		void	announce();

		// Setter
		void	setName(std::string name);

		// Destructeur
		~Zombie();
};

// Créer une horde de n zombie, les nomme tous pareil et renvois le pointeur 
// vers le premier
Zombie	*zombieHorde(int n, std::string name);

#endif
