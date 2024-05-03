/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:07:39 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/03 16:26:06 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int	main()
{
	Array<int>	test;

	try
	{
		std::cout << "------------------ Premier test ---------------" << std::endl;
		std::cout << test[0] << std::endl;
		test[0] = 5;
		std::cout << test[0] << std::endl;
		std::cout << test[1]  << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << "Error : " << expt.what() << std::endl;
	}

	Array<std::string>	test2(3);

	try
	{
		test2[0] = "Bonjour";
		test2[1] = "je m'appel";
		test2[2] = "Gertrude";
		std::cout << "------------------ Second test ---------------" << std::endl;
		std::cout << test2[0] << std::endl;
		std::cout << test2[1] << std::endl;
		std::cout << test2[2] << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << "Error : " << expt.what() << std::endl;
	}
	return (0);
}
