/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:07:05 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/19 10:41:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>
#include <cstring>

// static std::string	print(std::string &str)
// {
// 	std::cout << str << std::endl;
// 	return (str);
// }

static const std::string	print(const std::string &str)
{
	std::cout << str << std::endl;
	return (str);
}

static std::string	add(std::string &str)
{
	str[0] = str[0] + 5;
	return (str);
}

int	main()
{
	// Premier test
	std::cout << "------------------ Test 1 ---------------------" << std::endl;
	std::string	test1[3] = {"Bonjour", "je m'appel", "Gestrude"};

	iter(test1, 3, print);

	// Deuxieme test
	std::cout << std::endl << "------------------ Test 2 ---------------------" << std::endl;
	std::string	test2[3] = {"Bonjour", "je m'appel", "Gestrude"};

	iter(test2, 3, add);
	iter(test2, 3, print);

	// Troisieme test
	std::cout << std::endl << "------------------ Test 3 ---------------------" << std::endl;
	const std::string	test3[3] = {"Bonjour", "je m'appel", "Gestrude"};

	iter(test3, 3, print);
	return (0);
}
