/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:31:01 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/23 17:11:11 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	private:
		std::string	*ideas;

	public:
		// Constructors
		Brain();
		Brain(const Brain &cpy);

		// Surcharge d'opérateur
		Brain		&operator=(const Brain &cpy);

		// Fonction membre
		std::string	getIdeaNB(const int nb) const;
		void		putIdea(const int nb, const std::string idea);

		// Destructeur
		~Brain();
};
#endif