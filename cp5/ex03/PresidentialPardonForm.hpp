/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:07:19 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/30 18:41:31 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		const std::string	_target;
		PresidentialPardonForm();

	public:
		// Constructeur
		PresidentialPardonForm(const std::string target);

		// Surcharge d'opérateur
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &cpy);

		// Setter
		// Getter
		const std::string		getTarget() const;

		// Fonctions membres
		virtual void			execute(Bureaucrat const &executor) const;

		// Classes d'exception
		// Destructeur
		~PresidentialPardonForm();
};

#endif