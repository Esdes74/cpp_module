/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:29:27 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/22 10:31:52 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructeur
Cat::Cat()
{
	std::cout << "Default constructor from Cat class called" << std::endl;
	this->type = "cat";
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	std::cout << "Copy constructor from Cat class called" << std::endl;
	*this = cpy;
}

// Surcharge d'opérateur
Cat	&Cat::operator=(const Cat &cpy)
{
	std::cout << "Assignation operator from Cat class called" << std::endl;
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
	std::cout << "Destructor from Cat class called" << std::endl;
}