/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:20:58 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/24 19:56:16 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructeur
Dog::Dog()
{
	std::cout << "Constructeur par défaut de la classe Dog appelé" << std::endl;
	this->type = "dog";
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	std::cout << "Constructeur par copie de la classe Dog appelé" << std::endl;
	*this = cpy;
}

// Surcharge d'opérateur
Dog		&Dog::operator=(const Dog &cpy)
{
	std::cout << "Surcharge d'opérateur d'affectation de la classe Dog appelé" << std::endl;
	if (this != &cpy)
		Animal::operator=(cpy);
	return (*this);
}

// Fonctions membres
void	Dog::makeSound(void) const
{
	std::cout << "WAAf waaaf" << std::endl;
}

// Destructeur
Dog::~Dog()
{
	std::cout << "Destructeur de la classe Dog appelé" << std::endl;
}