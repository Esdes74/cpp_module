/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:06:26 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/30 18:44:21 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructeur
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	:AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

// Surcharge d'opérateur
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	AForm::operator=(cpy);
	return (*this);
}

// Setter
// Getter
const std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

// Fonctions membres
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	int	max(2);
	int	min(1);
	int	random_nb;

	verifNotSignedFormThrow();
	verifTooLowExeThrow(executor.getGrade());
	std::srand(std::time(0));
	random_nb = min + std::rand() % (max - min + 1);
	std::cout << "*Some noises of drills and shouts echo*" << std::endl;
	if (random_nb > 1)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy on " << _target << " has failed" << std::endl;
}

// Classes abstraites
// Destructeur
RobotomyRequestForm::~RobotomyRequestForm()
{
}
