/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:05:39 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/30 19:23:49 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
	private:
		const std::string _target;
		ShrubberyCreationForm();

	public:
		// Constructeur
		ShrubberyCreationForm(const std::string target);

		// Surcharge d'opérateur
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &cpy);

		// Setter
		// Getter
		const std::string		getTarget() const;

		// Fonctions membres
		void					verifFileOpenedThrow(std::ofstream &file) const;
		virtual void			execute(Bureaucrat const &executor) const;

		// Classes d'exceptions
		class FileNotOpenException: public AFormException
		{
			public:
				virtual const char	*what() const throw();
		};

		// Destructeur
		~ShrubberyCreationForm();
};

#endif