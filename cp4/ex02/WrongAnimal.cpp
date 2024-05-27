/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:55:44 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/22 10:51:19 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructeurs
WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor from WrongAnimal class called" << std::endl;
	type = "animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
	std::cout << "Copy constructor from WrongAnimal class called" << std::endl;
	*this = cpy;
}

// Surcharge d'opérateur
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &cpy)
{
	std::cout << "Assignation operator from WrongAnimal class called" << std::endl;
	if (this != &cpy)
		*this = cpy;
	return (*this);
}

// Getters
const std::string	&WrongAnimal::getType() const
{
	std::cout << "Getter from WrongAnimal class called" << std::endl;
	return (this->type);
}

// Fonctions membres
void	WrongAnimal::makeSound(void) const
{
	std::cout << "Any wrong animal makes any wrong noise" << std::endl;
}

// Destructeurs
WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor from WrongAnimal class called" << std::endl;
}