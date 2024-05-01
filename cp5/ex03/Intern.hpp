/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:30:03 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/01 12:40:25 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# define SIZE 9

# include "AForm.hpp"

class Intern
{
	public:
		// Constructeur
		Intern();
		Intern(const Intern &cpy);

		// Surcharge d'operateur
		Intern	&operator=(const Intern &cpy);

		// Fonctions membres
		AForm	*makeForm(std::string name, std::string target) const;

		// Classes d'exceptions
		class	FormNotExistException: public std::exception
		{
			virtual const char	*what() const throw();
		};

		class	SwitchFailureException: public std::exception
		{
			virtual const char	*what() const throw();
		};

		// Destructeur
		~Intern();
};

#endif