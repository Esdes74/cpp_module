/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:20:10 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 12:06:37 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon	*weapon;

	public:
		// Constructeur
		HumanB(std::string name);

		// Setter
		void	setWeapon(Weapon &weapon);

		// Fonction membre
		void	attack();
};
#endif
