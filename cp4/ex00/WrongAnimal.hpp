/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:51:24 by eslamber          #+#    #+#             */
/*   Updated: 2024/03/01 14:57:50 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <ostream>
# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	
	public:
		// Constructeur
		WrongAnimal();
		WrongAnimal(const WrongAnimal &cpy);

		// Surcharge d'opérateur
		WrongAnimal				&operator=(const WrongAnimal &cpy);

		// Getters
		const std::string	&getType() const;

		// Fonctions membres
		void				makeSound(void) const;

		// Destructeurs
		virtual	~WrongAnimal();
};

#endif