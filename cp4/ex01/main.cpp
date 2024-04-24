/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:47:34 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/24 15:12:56 by eslamber         ###   ########.fr       */
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
	Cat	cat;

	dog1.putIdea("manger des fraises");
	dog0 = dog1;
	Dog dog2(dog1);
	std::cout << dog0.lastIdea() << std::endl;
	std::cout << dog1.lastIdea() << std::endl;
	std::cout << dog2.lastIdea() << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	dog1.putIdea("manger des cerises");
	std::cout << dog0.lastIdea() << std::endl;
	std::cout << dog1.lastIdea() << std::endl;
	std::cout << dog2.lastIdea() << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	dog2.putIdea("manger des chats");
	std::cout << dog0.lastIdea() << std::endl;
	std::cout << dog1.lastIdea() << std::endl;
	std::cout << dog2.lastIdea() << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	dog0.putIdea("manger des framboises");
	std::cout << dog0.lastIdea() << std::endl;
	std::cout << dog1.lastIdea() << std::endl;
	std::cout << dog2.lastIdea() << std::endl;
	std::cout << cat.lastIdea() << std::endl;

	return 0;
}