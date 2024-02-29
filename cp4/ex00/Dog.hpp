/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:21:24 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/29 18:53:12 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
	public:
		// Constructeur
		Dog();
		Dog(const Dog &cpy);

		// Surcharge d'opérateur
		Dog		&operator=(const Dog &cpy);

		// Fonctions membres
		void	makeSound(void) const;

		// Destructeur
		~Dog();
};

#endif