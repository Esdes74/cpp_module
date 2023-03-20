/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:40:28 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/20 10:27:14 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
using namespace std;

int	main(int ac, char **av)
{
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
	return (0);
}
