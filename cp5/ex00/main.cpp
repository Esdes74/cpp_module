/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:06:13 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/29 12:39:39 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	Bureaucrat	bob("bob", 0);
	Bureaucrat	joseline("joseline", 176);
	Bureaucrat	bernard("bernard", 57);

	try
	{
		bob.verifGradeThrow();
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &expt)
	{
		std::cerr << bob.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &expt)
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
	catch (const Bureaucrat::GradeTooLowException &expt)
	{
		std::cerr << joseline.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &expt)
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
	catch (const Bureaucrat::GradeTooLowException &expt)
	{
		std::cerr << bernard.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &expt)
	{
		std::cerr << bernard.getName() << " : " << expt.what() << std::endl;
		std::cerr << "--------------------" << std::endl;
	}
	return (0);
}