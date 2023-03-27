/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:20:10 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/18 10:31:40 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		string	name;
		Weapon	*weapon;

	public:
		// Constructeur
		HumanB(string name);

		// Setter
		void	setWeapon(Weapon &weapon);

		// Fonction membre
		void	attack();
};
#endif
