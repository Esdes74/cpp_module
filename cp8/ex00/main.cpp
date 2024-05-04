/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:06:32 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/04 20:33:59 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main()
{
	std::vector<int>			vec;
	std::vector<int>::iterator	found;
	int							nbr(50);

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	vec.push_back(60);
	vec.push_back(70);
	vec.push_back(80);
	vec.push_back(90);
	vec.push_back(100);
	std::cout << vec[4] << std::endl;
	try
	{
		std::cout << "let's try to find " << nbr << std::endl;
		found = easyfind(vec, nbr);
		std::cout << vec[4] << std::endl;
		std::cout << *found << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << expt.what() << std::endl;
	}
	return (0);
}