/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:40:28 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/20 16:05:05 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
using namespace std;

static int	strlen(char *str)
{
	int	i(0);

	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		s;
	string	line;
	string	replace_name;
	string	p_replace = ".replace";

	if (ac != 4)
		return (1);
	ifstream file(av[1]);
	if (!file)
		return (1);
	replace_name = string(av[1]) + p_replace;
	ofstream replace(replace_name.c_str());
	if (!replace)
		return (1);
	while (getline(file, line))
	{
		i = 0;
		while (line[i] != '\0')
		{
			j = 0;
			s = i;
			while (line[s++] == av[2][j] && av[2][j] != '\0' && av[2][0] != 0)
				j++;
			if (j == strlen(av[2]) && j != 0)
			{
				i += j;
				j = 0;
				while (av[3][j] != '\0')
					replace << av[3][j++];
			}
			else
				replace << line[i++];
		}
	}
	return (0);
}
