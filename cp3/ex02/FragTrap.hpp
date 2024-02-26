/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:32:39 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/26 16:43:32 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		// Constructeurs
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &cpy);

		// Surcharge d'opérateur
		FragTrap		&operator=(const FragTrap &trap);

		// Fonctions membres
		void	highFivesGuys() const;

		// Destructor
		~FragTrap();
};

#endif
