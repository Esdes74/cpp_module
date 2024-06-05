/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:01:28 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/05 16:26:34 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>

int	main(int ac, char **av)
{
	int			j;
	int			i;
	PmergeMe	sort;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			sort.pushNumber(std::atoi(&av[i][j]));
			while (av[i][j] != ' ' && av[i][j] != '\0')
				j++;
		}
		i++;
	}
	sort.sort();
	std::cout << sort << std::endl;
	return (0);
}
