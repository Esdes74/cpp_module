/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:05:39 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/29 19:52:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructeur
ShrubberyCreationForm::ShrubberyCreationForm()
	:AForm("ShrubberyCreationForm", 145, 137), target(0)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const Bureaucrat &target)
	:AForm("ShrubberyCreationForm", 145, 137), target(&target)
{
}

// Surcharge d'opérateur
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	AForm::operator=(cpy);
}

// Setter
// Getter
const Bureaucrat	&ShrubberyCreationForm::getTarget() const
{
	return (this->target)
}

// Fonctions membres
virtual void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const;

// Classes abstraites
// Destructeur
~ShrubberyCreationForm::ShrubberyCreationForm()
{
}
