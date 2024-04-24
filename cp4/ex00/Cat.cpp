/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:29:27 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/24 19:56:01 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructeur
Cat::Cat()
{
	std::cout << "Constructeur par defaut de la classe Cat appelé" << std::endl;
	this->type = "cat";
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	std::cout << "Constructeur par copie de la classe Cat appelé" << std::endl;
	*this = cpy;
}

// Surcharge d'opérateur
Cat	&Cat::operator=(const Cat &cpy)
{
	std::cout << "Surcharge d'opérateur d'affectation de la classe Cat appelé" << std::endl;
	if (this != &cpy)
		Animal::operator=(cpy);
	return (*this);
}

// Fonctions membres
void	Cat::makeSound(void) const
{
	std::cout << "Miiiiaaaou !!" << std::endl;
}

// Destructeur
Cat::~Cat()
{
	std::cout << "Destructeur de la classe Cat appelé" << std::endl;
}