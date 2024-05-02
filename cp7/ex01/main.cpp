/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:07:05 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/02 20:10:02 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

static int	toUpperChar(const char &c)
{
	return std::toupper(static_cast<unsigned char>(c));
}

int	main()
{
	std::string	test("parfait");
	
	iter(&test[0], test.length(), toUpperChar);
	std::cout << test << std::endl;
	return (0);
}
