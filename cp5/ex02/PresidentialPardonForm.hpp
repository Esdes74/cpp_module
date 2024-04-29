/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:07:19 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/29 20:01:36 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

class PresidentialPardonForm: public AForm
{
	private:
		const Bureaucrat	&target;

	public:
		// Constructeur
		PresidentialPardonForm();
		PresidentialPardonForm(const Bureaucrat &target);

		// Surcharge d'opérateur
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &cpy);

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
		~PresidentialPardonForm();
};

#endif