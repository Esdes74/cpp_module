/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:39:03 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/17 14:11:55 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

using namespace std;

class Zombie
{
	private:
		string	name;

	public:
		// Constructeur
		Zombie(string name = "");

		// Fonction membre
		void	announce();

		// Setter
		void	setName(string name);

		// Destructeur
		~Zombie();
};

// Créer une horde de n zombie, les nomme tous pareil et renvois le pointeur 
// vers le premier
Zombie	*zombieHorde(int n, string name);

#endif
