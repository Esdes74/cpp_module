/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:06:13 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/29 19:04:51 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

int	main()
{
	Bureaucrat	bob("bob", 0);
	Bureaucrat	joseline("joseline", 176);
	Bureaucrat	bernard("bernard", 57);
	AForm		robotic("robotic", 140, 125);
	AForm		ai("ai", 3, 0);
	AForm		excavation("excavation", 145, 156);
	AForm		command("command", 30, 20);

	try
	{
		bob.verifGradeThrow();
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << bob.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}
	
	
	try
	{
		joseline.verifGradeThrow();
		std::cout << joseline << std::endl;
		joseline.incrementGrade();
		std::cout << joseline << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << joseline.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}
	

	try
	{
		bernard.verifGradeThrow();
		std::cout << bernard << std::endl;
		bernard.incrementGrade();
		std::cout << bernard << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << bernard.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}


	try
	{
		robotic.verifGradeThrow();
		std::cout << robotic << std::endl;
		robotic.beSigned(bernard);
		std::cout << robotic << std::endl;
	}
	catch (const AForm::GradeTooLowSgnException &expt)
	{
		std::cerr << bernard.getName() << " : " << expt.what() << \
		" to sign " << robotic.getName() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << robotic.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}


	try
	{
		ai.verifGradeThrow();
		std::cout << ai << std::endl;
		ai.beSigned(bernard);
		std::cout << ai << std::endl;
	}
	catch (const AForm::GradeTooLowSgnException &expt)
	{
		std::cerr << bernard.getName() << " : " << expt.what() << \
		" to sign " << ai.getName() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << ai.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}


	try
	{
		excavation.verifGradeThrow();
		std::cout << excavation << std::endl;
		excavation.beSigned(bernard);
		std::cout << excavation << std::endl;
	}
	catch (const AForm::GradeTooLowSgnException &expt)
	{
		std::cerr << bernard.getName() << " : " << expt.what() << \
		" to sign " << excavation.getName() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << excavation.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}


	try
	{
		command.verifGradeThrow();
		std::cout << command << std::endl;
		command.beSigned(bernard);
		std::cout << command << std::endl;
	}
	catch (const AForm::GradeTooLowSgnException &expt)
	{
		std::cerr << bernard.getName() << " : " << expt.what() << \
		" to sign " << command.getName() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << command.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}
	return (0);
}