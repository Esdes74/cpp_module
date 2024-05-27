/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:20:58 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/22 10:33:01 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructeur
Dog::Dog()
{
	std::cout << "Default constructor from Dog class called" << std::endl;
	this->type = "dog";
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	std::cout << "Copy constructor from Dog class called" << std::endl;
	*this = cpy;
}

// Surcharge d'opérateur
Dog		&Dog::operator=(const Dog &cpy)
{
	std::cout << "Assignation operator from Dog class called" << std::endl;
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
	std::cout << "Destructor from Dog class called" << std::endl;
}