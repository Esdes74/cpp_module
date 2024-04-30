/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:07:19 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/30 18:40:35 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructeur
PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	:AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

// Surcharge d'opérateur
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
	AForm::operator=(cpy);
	return (*this);
}

// Setter
// Getter
const std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

// Fonctions membres
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	verifNotSignedFormThrow();
	verifTooLowExeThrow(executor.getGrade());
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}

// Classes abstraites
// Destructeur
PresidentialPardonForm::~PresidentialPardonForm()
{
}
