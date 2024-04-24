/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:55:44 by eslamber          #+#    #+#             */
/*   Updated: 2024/03/01 14:56:55 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructeurs
WrongAnimal::WrongAnimal()
{
	std::cout << "Constructeur par défaut de la classe WrongAnimal appelé" << std::endl;
	type = "animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
	std::cout << "Constructeur par copie de la classe WrongAnimal appelé" << std::endl;
	*this = cpy;
}

// Surcharge d'opérateur
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &cpy)
{
	std::cout << "Opérateur d'affectation de la classe WrongAnimal appelé" << std::endl;
	if (this != &cpy)
		*this = cpy;
	return (*this);
}

// Getters
const std::string	&WrongAnimal::getType() const
{
	std::cout << "Getter de la classe animal appelé" << std::endl;
	return (this->type);
}

// Fonctions membres
void	WrongAnimal::makeSound(void) const
{
	std::cout << "Un animal quelconque fait un bruit quelconque" << std::endl;
}

// Destructeurs
WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructeur de la classe WrongAnimal appelé" << std::endl;
}