/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:21:24 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/22 14:14:40 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain	*brain;
		int		max_idea;

	public:
		// Constructeur
		Dog();
		Dog(const Dog &cpy);

		// Surcharge d'opérateur
		Dog			&operator=(const Dog &cpy);

		// Fonctions membres
		void		makeSound(void) const;
		void		putIdea(const std::string idea);
		std::string	lastIdea(void) const;

		// Destructeur
		~Dog();
};
#endif