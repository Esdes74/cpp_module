/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:32:39 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/28 16:38:03 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class Fragtrap: public Claptrap
{
	public:
		// Constructeurs
		Fragtrap();
		Fragtrap(const string &name);
		Fragtrap(const Fragtrap &cpy);

		// Fonctions membres
		void	highFivesGuys();

		// Destructor
		~Fragtrap();
};

#endif
