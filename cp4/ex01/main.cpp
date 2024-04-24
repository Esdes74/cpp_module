/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:47:34 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/23 20:24:08 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	Dog	dog0;
	Dog	dog1;

	dog1.putIdea("manger des fraises");
	dog0 = dog1;
	std::cout << dog0.lastIdea() << std::endl;
	std::cout << dog1.lastIdea() << std::endl;
	dog0.putIdea("manger des framboises");
	std::cout << dog0.lastIdea() << std::endl;
	std::cout << dog1.lastIdea() << std::endl;

	return 0;
}