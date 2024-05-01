/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:06:13 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/01 12:43:52 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat				bob("bob", 80);
	Bureaucrat				joseline("joseline", 5);
	Bureaucrat				bernard("bernard", 3);
	PresidentialPardonForm	president("Anthoine DANIEL");
	RobotomyRequestForm		robot("bob");
	ShrubberyCreationForm	shrubbery("home");
	Intern					intern;
	AForm					*ret_intern;

	try
	{
		bob.verifGradeThrow();
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
		shrubbery.verifGradeThrow();
		joseline.signForm(shrubbery);
		joseline.executeForm(shrubbery);
	}
	catch (const Bureaucrat::BureaucratException &expt)
	{
		std::cerr << bob.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}
	catch (const AForm::AFormException &expt)
	{
		std::cerr << shrubbery.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}

	try
	{
		joseline.verifGradeThrow();
		std::cout << joseline << std::endl;
		joseline.incrementGrade();
		std::cout << joseline << std::endl;
		robot.verifGradeThrow();
		joseline.signForm(robot);
		joseline.executeForm(robot);
	}
	catch (const Bureaucrat::BureaucratException &expt)
	{
		std::cerr << joseline.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}
	catch (const AForm::AFormException &expt)
	{
		std::cerr << robot.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}

	try
	{
		bernard.verifGradeThrow();
		std::cout << bernard << std::endl;
		bernard.incrementGrade();
		std::cout << bernard << std::endl;
		president.verifGradeThrow();
		bernard.signForm(president);
		bernard.executeForm(president);
	}
	catch (const Bureaucrat::BureaucratException &expt)
	{
		std::cerr << bernard.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}
	catch (const AForm::AFormException &expt)
	{
		std::cerr << president.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}

	ret_intern = intern.makeForm("President Pardon", "Jimmy Mc Guill");
	ret_intern = intern.makeForm("Presidential Pardon", "Jimmy Mc Guill");
	bob.executeForm(const_cast<AForm&>(*ret_intern));
	delete ret_intern;
	return (0);
}