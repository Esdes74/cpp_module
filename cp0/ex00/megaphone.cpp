/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:18:50 by eslamber          #+#    #+#             */
/*   Updated: 2024/03/11 15:15:52 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char *av[])
{
	int		i(1);
	int		j;

	while (av[i] != 0)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			char	c(toupper(av[i][j++]));
			std::cout << c;
		}
		i++;
	}
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
