/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:58:48 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/05 16:18:51 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>

int	main(int ac, char *av[])
{
	(void) ac;
	int	i;
	int	j;
	RPN	revers;

	try
	{
		i = 1;
		while (i < ac)
		{
			j = 0;
			while (av[i][j])
			{
				if ((av[i][j] != ' ' && av[i][j + 1] != ' ' && av[i][j + 1] != '\0'))
					throw std::invalid_argument("Error: bad arguments: missing space");
				else if (av[i][j] == '+')
					revers.addNumber();
				else if (av[i][j] == '-')
					revers.susNumber();
				else if (av[i][j] == '*')
					revers.mulNumber();
				else if (av[i][j] == '/')
					revers.divNumber();
				else if (std::isdigit(av[i][j]))
					revers.pushNumber(av[i][j] - '0');
				else if (av[i][j] != ' ')
					throw std::invalid_argument("Error: bad arguments: not number or operand");
				j++;
			}
			i++;
		}
		revers.printRes();
	}
	catch (const std::exception &expt)
	{
		std::cerr << expt.what() << std::endl;
	}
	return (0);
}
