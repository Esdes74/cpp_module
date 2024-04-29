/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:19:21 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/29 19:04:31 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructeur
AForm::AForm()
	:_name(""), _sgn(false), _reqSgn(100), _reqExe(50)
{
}

AForm::AForm(const std::string &name, const int gradeSign, const int gradeExec)
	:_name(name), _sgn(false), _reqSgn(gradeSign), _reqExe(gradeExec)
{
}

AForm::AForm(const AForm &cpy)
	:_name(cpy._name), _reqSgn(cpy._reqSgn), _reqExe(cpy._reqExe)
{
	if (this != &cpy)
		*this = cpy;
}

// Surcharge d'opérateur
AForm	&AForm::operator=(const AForm &cpy)
{
	this->_sgn = cpy._sgn;
	return (*this);
}

// Fonctions membres
void	AForm::verifGradeThrow() const
{
	if (this->_reqExe < 1)
		throw AForm::GradeTooHighException();
	else if (this->_reqExe > 149)
		throw AForm::GradeTooLowException();
	if (this->_reqSgn < 1)
		throw AForm::GradeTooHighException();
	else if (this->_reqSgn > 149)
		throw AForm::GradeTooLowException();
}

void	AForm::verifTooLowSgnThrow(const int grade) const
{
	if (grade > this->_reqSgn)
		throw AForm::GradeTooLowSgnException();
}

void	AForm::beSigned(const Bureaucrat &bu)
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
const std::string	&AForm::getName() const
{
	return (this->_name);
}

const bool	&AForm::getSgn() const
{
	return (this->_sgn);
}

const int	&AForm::getReqSgn() const
{
	return (this->_reqSgn);
}

const int	&AForm::getReqExe() const
{
	return (this->_reqExe);
}

// Classes d'exception
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too High");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}

const char	*AForm::GradeTooLowSgnException::what() const throw()
{
	return ("Grade too Low");
}

// Destructeur
AForm::~AForm()
{
}

std::ostream	&operator<<(std::ostream &os, AForm &out)
{
	os << out.getName() << " with a required grade " << out.getReqSgn() << " to sign it and ";
	os << out.getReqExe() << " to execute it";
	if (out.getSgn())
		os << " is signed ";
	else
		os << " isn't signed ";
	return (os);
}