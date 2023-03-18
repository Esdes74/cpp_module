/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:01:16 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/18 10:27:50 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		string	name;
		Weapon	*weapon;

	public:
		// Constructeur
		HumanA(string name, Weapon &weapon);

		// Fonction membre
		void	attack();
};
#endif
