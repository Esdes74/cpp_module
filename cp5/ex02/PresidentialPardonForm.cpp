/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:07:19 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/29 20:06:37 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructeur
PresidentialPardonForm::PresidentialPardonForm()
	:AForm("PresidentialPardonForm", 25, 5), target(0)
{
}

PresidentialPardonForm::PresidentialPardonForm(const Bureaucrat &target)
	:AForm("PresidentialPardonForm", 25, 5), target(&target)
{
}

// Surcharge d'opérateur
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
	AForm::operator=(cpy);
}

// Setter
// Getter
const Bureaucrat	&PresidentialPardonForm::getTarget() const
{
	return (this->target)
}

// Fonctions membres
virtual void	PresidentialPardonForm::execute(Bureaucrat const &executor) const;

// Classes abstraites
const char	*PresidentialPardonForm::GradeTooLowExeException::what() const throw()
{
	return ("Grade too Low to execute")
}

// Destructeur
~PresidentialPardonForm::PresidentialPardonForm()
{
}
