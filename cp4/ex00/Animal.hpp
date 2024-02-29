/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:54:02 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/29 17:45:35 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <ostream>
# include <iostream>

class Animal
{
	private:
		std::string	type;
	public:
		// Constructeurs
		Animal();
		Animal(const std::string	&name);
		Animal(const Animal &cpy);

		// Surcharge d'opérateur
		Animal	&operator=(const Animal &cpy);

		// Destructeurs
		virtual	~Animal();
};

#endif