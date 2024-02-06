/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:27:00 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 12:05:59 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string	test;
	std::string	*stringPTR;
	std::string	&stringREF(test);

	test = "HI THIS IS BRAIN";
	stringPTR = &test;

	std::cout << "L'adresse de la string est : " << &test << std::endl;
	std::cout << "L'adresse stockée dans stringPTR est : " << stringPTR << std::endl;
	std::cout << "L'adresse stockée dans stringREF est : " << &stringREF << std::endl << std::endl;

	std::cout << "La valeur stockée dans la string est : " << test << std::endl;
	std::cout << "La valeur pointée par le pointeur stringPTR est : " << *stringPTR \
		<< std::endl;
	std::cout << "La valeur pointée par stringREF est : " << stringREF << std::endl;
}
