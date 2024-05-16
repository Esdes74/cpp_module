/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:57:03 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/16 14:30:53 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main()
{
	try
	{
		const BitcoinExchange	*bit = BitcoinExchange::getInstance();
		(void) bit;
	}
	catch (const std::exception &expt)
	{
		std::cout << expt.what() << std::endl;;
	}
	return (0);
}