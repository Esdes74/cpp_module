/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:57:03 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/17 11:02:47 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int ac, char *av[])
{
	if (ac != 2)
		return (1);

	try
	{
		const BitcoinExchange	*bit = BitcoinExchange::getInstance();
		bit->printChange(av[1]);
	}
	catch (const std::exception &expt)
	{
		std::cout << expt.what() << std::endl;;
	}
	return (0);
}