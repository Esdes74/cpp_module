/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:54:41 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/29 19:01:58 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructeurs
Animal::Animal()
{
	std::cout << "Constructeur par défaut de la classe Animal appelé" << std::endl;
	type = "animal";
}

Animal::Animal(const std::string	&name)
{
	std::cout << "Constructeur par nom de la classe animal appelé" << std::endl;
	this->type = name;
}

Animal::Animal(const Animal &cpy)
{
	std::cout << "Constructeur par copie de la classe Animal appelé" << std::endl;
	*this = cpy;
}

// Surcharge d'opérateur
Animal	&Animal::operator=(const Animal &cpy)
{
	std::cout << "Opérateur d'affectation de la classe Animal appelé" << std::endl;
	if (this != &cpy)
		*this = cpy;
	return (*this);
}

// Getters
const std::string	&Animal::getType() const
{
	std::cout << "Getter de la classe animal appelé" << std::endl;
	return (this->type);
}

// Fonctions membres
void	Animal::makeSound(void) const
{
	std::cout << "Un animal quelconque fait un bruit quelconque" << std::endl;
}

// Destructeurs
Animal::~Animal()
{
	std::cout << "Destructeur de la classe Animal appelé" << std::endl;
}