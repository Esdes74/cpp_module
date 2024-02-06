/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:59:55 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 13:30:22 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class Scavtrap: public Claptrap
{
	public:
		// Constructeurs
		Scavtrap();
		Scavtrap(const std::string &name);
		Scavtrap(const Scavtrap &cpy);

		// Fonctions membres
		void	attack(const std::string &target);
		void	guardGate();

		// Destructor
		~Scavtrap();
};

#endif
