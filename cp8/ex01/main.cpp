/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:46:26 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/24 10:41:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int	main()
{
	Span	test(5);

	try
	{
		std::cout << "------------------------ Premier test -------------------------" << std::endl;
		test.addNumber(4);
		test.addNumber(50);
		test.addNumber(2);
		test.addNumber(6);
		test.addNumber(1);
		std::cout << "shortest : " << test.shortestSpan() << std::endl;
		std::cout << "longest : " <<  test.longestSpan() << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << expt.what() << std::endl;
	}

	Span	test2(5);

	try
	{
		std::cout << "\n------------------------ Deuxieme test -------------------------" << std::endl;
		test2.addNumber(2, 5);
		std::cout << "shortest : " << test2.shortestSpan() << std::endl;
		std::cout << "longest : " <<  test2.longestSpan() << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << expt.what() << std::endl;
	}

	Span	test3(5);

	try
	{
		std::cout << "\n------------------------ Troisieme test ------------------------" << std::endl;
		test3.addNumber(4, 5);
		std::cout << "shortest : " << test3.shortestSpan() << std::endl;
		std::cout << "longest : " <<  test3.longestSpan() << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << expt.what() << std::endl;
	}

	Span	test4(5);

	try
	{
		std::cout << "\n------------------------ Quatrieme test ------------------------" << std::endl;
		test4.addNumber(1, 50);
		std::cout << "shortest : " << test4.shortestSpan() << std::endl;
		std::cout << "longest : " <<  test4.longestSpan() << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << expt.what() << std::endl;
	}

	Span	test5(13000);

	try
	{
		std::cout << "\n------------------------ Cinquieme test ------------------------" << std::endl;
		test5.addNumber(1, 12999);
		test5.addNumber(-8);
		std::cout << "shortest : " << test5.shortestSpan() << std::endl;
		std::cout << "longest : " <<  test5.longestSpan() << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << expt.what() << std::endl;
	}
	return (0);
}
