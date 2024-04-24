/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:57:02 by eslamber          #+#    #+#             */
/*   Updated: 2024/03/01 14:58:14 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		// Constructeur
		WrongCat();
		WrongCat(const WrongCat &cpy);

		// Surcharge d'opérateur
		WrongCat		&operator=(const WrongCat &cpy);

		// Fonctions membres
		void	makeSound(void) const;

		// Destructeur
		~WrongCat();
};

#endif