/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:33:25 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/02 16:15:13 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main()
{
	SData		test;
	SData		*ret;
	uintptr_t	tmp;

	test.c = 'e';
	test.x = 42;
	test.f = 4.2f;
	test.d = 0.42;

	std::cout << "Voici la data avant la serialisation : " << std::endl;;
	std::cout << "data.c = " << test.c << std::endl;
	std::cout << "data.x = " << test.x << std::endl;
	std::cout << "data.f = " << test.f << std::endl;
	std::cout << "data.d = " << test.d << std::endl;

	tmp = Serializer::serialize(&test);
	ret = Serializer::deserialize(tmp);

	std::cout << "Voici la data apres la serialisation : " << std::endl;;
	std::cout << "data.c = " << ret->c << std::endl;
	std::cout << "data.x = " << ret->x << std::endl;
	std::cout << "data.f = " << ret->f << std::endl;
	std::cout << "data.d = " << ret->d << std::endl;
	return (0);
}