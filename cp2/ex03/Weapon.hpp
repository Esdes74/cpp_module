/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:51:19 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/18 10:27:43 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>
using namespace std;

class Weapon
{
	private:
		string	type;

	public:
		// Constucteur
		Weapon(string type);

		// Setter
		void	setType(string type);
		
		// Getter
		string	getType();
};
#endif
