/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:39:03 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/17 13:29:28 by eslamber         ###   ########.fr       */
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
		Zombie(string name);

		// Fonction membre
		void	announce();

		// Destructeur
		~Zombie();
};

// Créer un zombie et le retourne
Zombie	*newZombie(string name);

// Créer un zombie, le fait beugler et le détruit
void	randomChump(string name);

#endif
