/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:39:03 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 12:01:48 by eslamber         ###   ########.fr       */
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
		Zombie(std::string name);

		// Fonction membre
		void	announce();

		// Destructeur
		~Zombie();
};

// Créer un zombie et le retourne
Zombie	*newZombie(std::string name);

// Créer un zombie, le fait beugler et le détruit
void	randomChump(std::string name);

#endif
