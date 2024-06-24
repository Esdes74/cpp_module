/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:06:32 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/24 10:34:18 by eslamber         ###   ########.fr       */
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
	try
	{
		std::cout << "let's try to find " << nbr << std::endl;
		found = easyfind(vec, nbr);
		std::cout << "vec[4] = " << vec[4] << std::endl;
		std::cout << "found = " << *found << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << expt.what() << std::endl;
	}

	const std::vector<int>		vec2(vec);
	std::vector<int>::iterator	found2;
	int							nbr2(50);

	// vec2.push_back(10);
	// vec2.push_back(20);
	// vec2.push_back(30);
	// vec2.push_back(40);
	// vec2.push_back(50);
	// vec2.push_back(60);
	// vec2.push_back(70);
	// vec2.push_back(80);
	// vec2.push_back(90);
	// vec2.push_back(100);
	try
	{
		std::cout << "let's try to find " << nbr2 << std::endl;
		found2 = easyfind(vec2, nbr2);
		std::cout << "vec2[4] = " << vec2[4] << std::endl;
		std::cout << "found2 = " << *found2 << std::endl;
	}
	catch (const std::exception &expt)
	{
		std::cerr << expt.what() << std::endl;
	}
	return (0);
}