/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:19:21 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/29 18:53:31 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructeur
Form::Form()
	:_name(""), _sgn(false), _reqSgn(100), _reqExe(50)
{
}

Form::Form(const std::string &name, const int gradeSign, const int gradeExec)
	:_name(name), _sgn(false), _reqSgn(gradeSign), _reqExe(gradeExec)
{
}

Form::Form(const Form &cpy)
	:_name(cpy._name), _reqSgn(cpy._reqSgn), _reqExe(cpy._reqExe)
{
	if (this != &cpy)
		*this = cpy;
}

// Surcharge d'opérateur
Form	&Form::operator=(const Form &cpy)
{
	this->_sgn = cpy._sgn;
	return (*this);
}

// Fonctions membres
void	Form::verifGradeThrow() const
{
	if (this->_reqExe < 1)
		throw Form::GradeTooHighException();
	else if (this->_reqExe > 149)
		throw Form::GradeTooLowException();
	if (this->_reqSgn < 1)
		throw Form::GradeTooHighException();
	else if (this->_reqSgn > 149)
		throw Form::GradeTooLowException();
}

void	Form::verifTooLowSgnThrow(const int grade) const
{
	if (grade > this->_reqSgn)
		throw Form::GradeTooLowSgnException();
}

void	Form::beSigned(const Bureaucrat &bu)
{
	verifTooLowSgnThrow(bu.getGrade());
	if (this->_sgn)
		std::cout << bu.getName() << " couldn't sign " << _name << \
	" because he already signed it\n";
	else
	{
		this->_sgn = true;
		bu.signForm(_name);
	}
}

// Getters
const std::string	&Form::getName() const
{
	return (this->_name);
}

const bool	&Form::getSgn() const
{
	return (this->_sgn);
}

const int	&Form::getReqSgn() const
{
	return (this->_reqSgn);
}

const int	&Form::getReqExe() const
{
	return (this->_reqExe);
}

// Classes d'exception
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too High");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}

const char	*Form::GradeTooLowSgnException::what() const throw()
{
	return ("Grade too Low");
}

// Destructeur
Form::~Form()
{
}

std::ostream	&operator<<(std::ostream &os, Form &out)
{
	os << out.getName() << " with a required grade " << out.getReqSgn() << " to sign it and ";
	os << out.getReqExe() << " to execute it";
	if (out.getSgn())
		os << " is signed ";
	else
		os << " isn't signed ";
	return (os);
}