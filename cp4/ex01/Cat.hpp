/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:29:44 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/23 16:14:44 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain	*brain;

	public:
		// Constructeur
		Cat();
		Cat(const Cat &cpy);

		// Surcharge d'opérateur
		Cat		&operator=(const Cat &cpy);

		// Fonctions membres
		void	makeSound(void) const;

		// Destructeur
		~Cat();
};

#endif