/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:32:39 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 13:34:24 by eslamber         ###   ########.fr       */
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
		Fragtrap(const std::string &name);
		Fragtrap(const Fragtrap &cpy);

		// Fonctions membres
		void	highFivesGuys();

		// Destructor
		~Fragtrap();
};

#endif
