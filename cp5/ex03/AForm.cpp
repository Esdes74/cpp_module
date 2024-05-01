/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:19:21 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/01 12:38:49 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructeur
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

void	AForm::verifSignedFormThrow() const
{
	if (_sgn)
		throw AForm::AlreadySignedFormException();
}

void	AForm::verifNotSignedFormThrow() const
{
	if (!_sgn)
		throw AForm::NotSignedFormException();
}

void	AForm::verifTooLowSgnThrow(const int grade) const
{
	if (grade > this->_reqSgn)
		throw AForm::GradeTooLowSgnException();
}

void	AForm::verifTooLowExeThrow(const int grade) const
{
	if (grade > this->_reqExe)
		throw AForm::GradeTooLowExeException();
}

void	AForm::beSigned(const Bureaucrat &bu)
{
	verifTooLowSgnThrow(bu.getGrade());
	verifSignedFormThrow();
	this->_sgn = true;
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
	return ("Grade too Low to sign");
}

const char	*AForm::GradeTooLowExeException::what() const throw()
{
	return ("Grade too Low to execute");
}

const char	*AForm::AlreadySignedFormException::what() const throw()
{
	return ("Form already signed");
}

const char	*AForm::NotSignedFormException::what() const throw()
{
	return ("Form not signed");
}

// Destructeur
AForm::~AForm()
{
}

// Surcharge d'operateur externe
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