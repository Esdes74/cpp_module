/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:58:28 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/22 10:36:44 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructeur
WrongCat::WrongCat()
{
	std::cout << "Default constructor from WrongCat class called" << std::endl;
	this->type = "cat";
}

WrongCat::WrongCat(const WrongCat &cpy) : WrongAnimal(cpy)
{
	std::cout << "Copy constructor from WrongCat class called" << std::endl;
	*this = cpy;
}

// Surcharge d'opérateur
WrongCat	&WrongCat::operator=(const WrongCat &cpy)
{
	std::cout << "Assignation operator from WrongCat class called" << std::endl;
	if (this != &cpy)
		WrongAnimal::operator=(cpy);
	return (*this);
}

// Fonctions membres
void	WrongCat::makeSound(void) const
{
	std::cout << "RIiiioooouuuu !!" << std::endl;
}

// Destructeur
WrongCat::~WrongCat()
{
	std::cout << "Destructor from WrongCat class called" << std::endl;
}
