/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:56:50 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/22 11:06:40 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

static int	strlen(char *str);

Sed::Sed(std::string name)
{
	this->name = name + ".replace";
}

void	Sed::setName(std::string name)
{
	this->name = name + ".replace";
}

int	Sed::replace(char *filename, char **av)
{
	int			i;
	int			j;
	int			s;
	std::size_t	len;
	std::string	line;

	std::ifstream file(filename);
	if (!file)
		return (1);
	std::ofstream replace(this->name.c_str());
	if (!replace)
		return (1);
	while (getline(file, line))
	{
		i = 0;
		len = line.length();
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
			else if (i < (int) len)
				replace << line[i++];
		}
		replace << std::endl;
	}
	return (0);
}

static int	strlen(char *str)
{
	int	i(0);

	while (str[i])
		i++;
	return (i);
}