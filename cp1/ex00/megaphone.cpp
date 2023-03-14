/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:18:50 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/14 16:14:30 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int	main(int ac, char *av[])
{
	int		i(1);
	int		j;
	char	test[1];

	while (av[i] != 0)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			char	c(toupper(av[i][j++]));
			cout << c;
		}
		i++;
	}
	if (i == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	cout << endl;
	return (0);
}
