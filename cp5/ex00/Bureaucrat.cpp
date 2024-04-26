/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:05:13 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/26 15:48:01 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructeurs
Bureaucrat::Bureaucrat()
{
	name = "";
	grade = 149;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->name = name;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
{
	if (this != &cpy)
		*this = cpy;
}

// Surcharge d'opérateur
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &cpy)
{
	this->name = cpy.name;
	this->grade = cpy.grade;
}

// Getters
const std::string	&Bureaucrat::getName() const
{
	return (this->name);
}

const int			&Bureaucrat::getGrade() const
{
	return (this->grade);
}

// Fonctions membres
void				Bureaucrat::incrementGrade()
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 149)
		throw Bureaucrat::GradeTooLowException();
	this->grade--;
}

void				Bureaucrat::decrementGrade();

// Exceptions
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

// Destructeur
Bureaucrat::~Bureaucrat()
{
	return ;
}

std::ostream	&operator<<(std::ostream os, const Bureaucrat &out)
{
	os << out.getName() << "is graded : " << out.getGrade() << std::endl;
}
