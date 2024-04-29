/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:06:26 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/29 19:51:59 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructeur
RobotomyRequestForm::RobotomyRequestForm()
	:AForm("RobotomyRequestForm", 72, 45), target(0)
{
}

RobotomyRequestForm::RobotomyRequestForm(const Bureaucrat &target)
	:AForm("RobotomyRequestForm", 72, 45), target(&target)
{
}

// Surcharge d'opérateur
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	AForm::operator=(cpy);
}

// Setter
// Getter
const Bureaucrat	&RobotomyRequestForm::getTarget() const
{
	return (this->target)
}

// Fonctions membres
virtual void	RobotomyRequestForm::execute(Bureaucrat const &executor) const;

// Classes abstraites
// Destructeur
~RobotomyRequestForm::RobotomyRequestForm()
{
}
