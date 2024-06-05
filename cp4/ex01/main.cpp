/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:47:34 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/04 14:07:26 by eslamber         ###   ########.fr       */
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

	std::cout << "\n================ Tests =================" << std::endl;
	Dog	dog0;
	Dog	dog1;
	Cat	cat;

	dog1.putIdea("eat some strawberries");
	dog0 = dog1;
	Dog dog2(dog1);
	std::cout << "------------- Test type -----------------" << std::endl;
	std::cout << dog0.getType() << std::endl;
	std::cout << dog1.getType() << std::endl;
	std::cout << dog2.getType() << std::endl;
	std::cout << cat.getType() << std::endl;
	std::cout << "------------- Test Ideas ----------------" << std::endl;
	std::cout << dog0.lastIdea() << std::endl;
	std::cout << dog1.lastIdea() << std::endl;
	std::cout << dog2.lastIdea() << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	dog1.putIdea("eat some cherries");
	std::cout << dog0.lastIdea() << std::endl;
	std::cout << dog1.lastIdea() << std::endl;
	std::cout << dog2.lastIdea() << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	dog2.putIdea("eat some cats");
	std::cout << dog0.lastIdea() << std::endl;
	std::cout << dog1.lastIdea() << std::endl;
	std::cout << dog2.lastIdea() << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	dog0.putIdea("eat some raspberries");
	std::cout << dog0 << std::endl;
	std::cout << dog1 << std::endl;
	std::cout << dog2 << std::endl;
	std::cout << cat << std::endl;

	std::cout << "\n============= Tests Leaks ==============" << std::endl;
	const Animal	*test = new Dog();
	delete test;

	std::cout << "\n=========== Tests Deep Copy ============" << std::endl;
	Dog	*test2 = new Dog;
	test2->putIdea("play with his baball");
	Dog	deep(*test2);
	test2->putIdea("sleep");
	std::cout << test2->lastIdea() << std::endl;
	std::cout << deep.lastIdea() << std::endl;
	delete test2;
	std::cout << deep.lastIdea() << std::endl;
	deep.putIdea("play");
	std::cout << deep.lastIdea() << std::endl;

	std::cout << "---------------------------------------------------\n";
	Cat	*test3 = new Cat;
	test3->putIdea("catch some rats");
	Cat	deep2(*test3);
	test3->putIdea("sleep");
	std::cout << test3->lastIdea() << std::endl;
	std::cout << deep2.lastIdea() << std::endl;
	delete test3;
	std::cout << deep2.lastIdea() << std::endl;
	deep2.putIdea("catch");
	std::cout << deep2.lastIdea() << std::endl;
	return 0;
}
