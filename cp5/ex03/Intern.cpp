/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:30:44 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/01 12:40:46 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static int		name_is_possible(const std::string str);
static int		verifFormNameThrow(std::string name);
static AForm	*action(std::string name, std::string target);

// Constructeur
Intern::Intern()
{
}

Intern::Intern(const Intern &cpy)
{
	(void)	cpy;
}

// Surcharge d'operateur
Intern	&Intern::operator=(const Intern &cpy)
{
	(void)	cpy;

	return (*this);
}

// Fonctions membres
AForm	*Intern::makeForm(std::string name, std::string target) const
{
	AForm	*form;

	try
	{
		form = action(name, target);
	}
	catch (const std::exception &expt)
	{
		std::cerr << expt.what() << std::endl;
	}
	return (form);
}

// Classes d'exceptions
const char	*Intern::FormNotExistException::what() const throw()
{
	return ("Intern : Form doesn't exist");
}

const char	*Intern::SwitchFailureException::what() const throw()
{
	return ("Intern : Switch case fail");
}

// Destructeur
Intern::~Intern()
{
}

// Statics
static int	name_is_possible(const std::string str)
{
	int			i;
	std::string	possible_name[SIZE] = {"shrubbery creation", "robotomy request", \
	"presidential pardon", "Shrubbery creation", "Robotomy request", \
	"Presidential pardon", "Shrubbery Creation", "Robotomy Request", \
	"Presidential Pardon"};

	i = 0;
    while (i < SIZE)
	{
        if (str == possible_name[i])
            return (i);
		i++;
    }
    return (i);
}

static int	verifFormNameThrow(std::string name)
{
	int	nb_form;

	nb_form = name_is_possible(name);
	if (nb_form == SIZE)
		throw Intern::FormNotExistException();
	return (nb_form);
}

static AForm	*action(std::string name, std::string target)
{
	int		nb_form;
	AForm	*form;

	form = NULL;
	nb_form = verifFormNameThrow(name);
	switch (nb_form % 3)
	{
		case (0):
			form = new ShrubberyCreationForm(target);
			break ;
		case (1):
			form = new RobotomyRequestForm(target);
			break ;
		case (2):
			form = new PresidentialPardonForm(target);
			break ;
		default:
			throw Intern::SwitchFailureException();
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return (form);
}
