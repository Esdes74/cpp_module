/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:54:02 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/23 18:21:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <ostream>
# include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		// Constructeurs
		Animal();
		Animal(const std::string &name);
		Animal(const Animal &cpy);

		// Surcharge d'opérateur
		Animal				&operator=(const Animal &cpy);

		// Getters
		const std::string	&getType() const;

		// Fonctions membres
		virtual void		makeSound(void) const;
		virtual void		putIdea(const std::string idea);
		virtual std::string	lastIdea(void) const;

		// Destructeurs
		virtual	~Animal();
};

#endif