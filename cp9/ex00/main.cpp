/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:57:03 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/28 13:41:51 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Please give an input file to treat\n";
		return (1);
	}

	try
	{
		BitcoinExchange::initilize();
		BitcoinExchange::printChange(av[1]);
	}
	catch (const std::exception &expt)
	{
		std::cerr << expt.what() << std::endl;;
	}
	return (0);
}