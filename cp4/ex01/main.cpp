/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:47:34 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/22 14:23:14 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	Animal	*tab[4] = {new Cat(), new Cat(), new Dog(), new Dog()};
	std::cout << *tab[0] << std::endl;
	std::cout << *tab[1] << std::endl;
	std::cout << *tab[2] << std::endl;
	delete tab[0];
	delete tab[1];
	delete tab[2];
	delete tab[3];
	std::cout << "================ Tests =================" << std::endl;
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
	std::cout << dog0 << std::endl;
	std::cout << dog1 << std::endl;
	std::cout << dog2 << std::endl;
	std::cout << cat << std::endl;
	std::cout << "============= Tests Leaks ==============" << std::endl;
	const Animal	*test = new Dog();
	delete test;
	return 0;
}