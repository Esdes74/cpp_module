/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:58:28 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/24 19:57:15 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructeur
WrongCat::WrongCat()
{
	std::cout << "Constructeur par defaut de la classe WrongCat appelé" << std::endl;
	this->type = "cat";
}

WrongCat::WrongCat(const WrongCat &cpy) : WrongAnimal(cpy)
{
	std::cout << "Constructeur par copie de la classe WrongCat appelé" << std::endl;
	*this = cpy;
}

// Surcharge d'opérateur
WrongCat	&WrongCat::operator=(const WrongCat &cpy)
{
	std::cout << "Surcharge d'opérateur d'affectation de la classe WrongCat appelé" << std::endl;
	if (this != &cpy)
		WrongAnimal::operator=(cpy);
	return (*this);
}

// Fonctions membres
void	WrongCat::makeSound(void) const
{
	std::cout << "Miiiiaaaou !!" << std::endl;
}

// Destructeur
WrongCat::~WrongCat()
{
	std::cout << "Destructeur de la classe WrongCat appelé" << std::endl;
}