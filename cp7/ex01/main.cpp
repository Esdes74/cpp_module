/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:07:05 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/03 10:51:27 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>
#include <cstring>

static int	toUpperChar(const char &c)
{
	return std::toupper(static_cast<unsigned char>(c));
}

static std::string	print(const std::string &str)
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
	char	test[] = "quoi ? je parle fort ?";
	
	iter(test, strlen(test), toUpperChar);
	std::cout << test << std::endl;

	// Seconde test
	std::cout << std::endl << "------------------ Test 2 ---------------------" << std::endl;
	std::string	test2[3] = {"Bonjour", "je m'appel", "Gestrude"};

	iter(test2, 3, print);

	// Troisieme test
	std::cout << std::endl << "------------------ Test 3 ---------------------" << std::endl;
	std::string	test3[3] = {"Bonjour", "je m'appel", "Gestrude"};

	iter(test3, 3, add);
	iter(test3, 3, print);
	return (0);
}
