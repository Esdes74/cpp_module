/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:05:13 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/29 16:34:54 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructeurs
Bureaucrat::Bureaucrat()
{
	_name = "";
	_grade = 149;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
{
	this->_name = name;
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
{
	if (this != &cpy)
		*this = cpy;
}

// Surcharge d'opérateur
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &cpy)
{
	this->_name = cpy._name;
	this->_grade = cpy._grade;
	return (*this);
}

// Getters
const std::string	&Bureaucrat::getName() const
{
	return (this->_name);
}

const int	&Bureaucrat::getGrade() const
{
	return (this->_grade);
}

// Fonctions membres
void	Bureaucrat::verifGradeThrow() const
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 149)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::incrementGrade()
{
	this->_grade--;
	Bureaucrat::verifGradeThrow();
}

void	Bureaucrat::decrementGrade()
{
	this->_grade++;
	Bureaucrat::verifGradeThrow();
}

void	Bureaucrat::signForm(const std::string &formName) const
{
	std::cout << _name << " signed " << formName << std::endl;
}

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

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &out)
{
	os << out.getName() << ", bureaucrat grade " << out.getGrade() << ".";
	return (os);
}
