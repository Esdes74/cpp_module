/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:47:34 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/22 13:42:52 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << "============== Right Tests ===============" << std::endl;
	const Animal*	ani = new Animal();
	const Animal*	dog = new Dog();
	Animal*			cat = new Cat();
	Animal			cat1("cat1");

	std::cout << cat->getType() << " : ";
	cat->makeSound(); //will output the cat sound!
	std::cout << std::endl;
	std::cout << dog->getType() << " : ";
	dog->makeSound();
	std::cout << std::endl;
	std::cout << ani->getType() << " : ";
	ani->makeSound();
	std::cout << std::endl;
	cat1 = *ani;
	std::cout << cat1.getType() << std::endl;
	delete ani;
	delete dog;
	delete cat;


	std::cout << "\n============== Wrong Tests ===============" << std::endl;
	const WrongAnimal*	ani2 = new WrongAnimal();
	WrongAnimal*	cat2 = new WrongCat();
	WrongAnimal		cat3;

	std::cout << cat2->getType() << " : ";
	cat2->makeSound();
	std::cout << std::endl;
	std::cout << ani2->getType() << " : ";
	ani2->makeSound();
	std::cout << std::endl;
	cat3 = *ani2;
	std::cout << cat3.getType() << std::endl;
	delete ani2;
	delete cat2;
	return 0;
}