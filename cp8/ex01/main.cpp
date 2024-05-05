/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:46:26 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/05 11:09:29 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int	main()
{
	Span	test(5);

	try
	{
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
	return (0);
}
