/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:33:18 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/17 18:06:43 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

static Base	*generate()
{
	int	nb;

	// Initilisation du random
    std::srand(std::time(NULL));

	// Choix du random, et conséquences
	nb = std::rand() % 3;
	switch (nb)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			std::cout << "Probleme avec la génération aléatoire\n";
			return (NULL);
	}
}

static void	identify(Base *base)
{
	if (dynamic_cast<A*>(base) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(base) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(base) != NULL)
		std::cout << "C" << std::endl;
}

static void	identify(Base &base)
{
	try
	{
		A a = dynamic_cast<A&>(base);
		std::cout << "A\n";
		(void) a;
		return ;
	}
	catch (const std::exception &expt)
	{
	}
	try
	{
		B b = dynamic_cast<B&>(base);
		std::cout << "B\n";
		(void) b;
		return ;
	}
	catch (const std::exception &expt)
	{
	}
	try
	{
		C c = dynamic_cast<C&>(base);
		std::cout << "C\n";
		(void) c;
		return ;
	}
	catch (const std::exception &expt)
	{
	}
}

int	main()
{
	Base	*test = generate();

	identify(test);
	identify(*test);
	delete test;
}