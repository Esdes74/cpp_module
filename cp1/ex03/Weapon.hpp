/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:51:19 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/21 10:19:35 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
	private:
		std::string	type;

	public:
		// Constucteur
		Weapon(std::string type);

		// Setter
		void	setType(std::string type);
		
		// Getter
		const std::string	&getType();
};
#endif
