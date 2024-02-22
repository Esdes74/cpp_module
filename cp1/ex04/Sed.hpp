/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:56:42 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/22 11:06:20 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <fstream>
#include <iostream>
#include <string>

class Sed
{
	private:
		std::string	name;

	public:
		// Constructeur
		Sed(std::string name);

		// Setter
		void	setName(std::string name);

		// Fonction membre
		int	replace(char *filename, char **av);
};

#endif