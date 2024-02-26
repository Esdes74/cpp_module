/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:59:55 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/26 15:53:43 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		// Constructeurs
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &cpy);

		// Surcharge d'opérateur
		ScavTrap	&operator=(const ScavTrap &trap);

		// Fonctions membres
		void		attack(const std::string &target);
		void		guardGate() const;

		// Destructor
		~ScavTrap();
};

#endif
