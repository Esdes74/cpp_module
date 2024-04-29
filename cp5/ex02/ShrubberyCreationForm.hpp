/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:05:39 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/29 20:01:22 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

class ShrubberyCreationForm: public AForm
{
	private:
		const Bureaucrat	&target;

	public:
		// Constructeur
		ShrubberyCreationForm();
		ShrubberyCreationForm(const Bureaucrat &target);

		// Surcharge d'opérateur
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &cpy);

		// Setter
		// Getter
		const Bureaucrat		&getTarget() const;

		// Fonctions membres
		virtual void			execute(Bureaucrat const &executor) const;

		// Classes abstraites
		class GradeTooLowExeException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		// Destructeur
		~ShrubberyCreationForm();
};

#endif