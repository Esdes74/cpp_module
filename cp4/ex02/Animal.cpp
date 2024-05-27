/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:54:41 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/22 14:37:03 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructeurs
Animal::Animal()
{
	std::cout << "Default constructor from Animal class called" << std::endl;
	type = "animal";
}

Animal::Animal(const std::string	&name)
{
	std::cout << "Name contructor from Animal class called" << std::endl;
	this->type = name;
}

Animal::Animal(const Animal &cpy)
{
	std::cout << "Copy constructor from Animal class called" << std::endl;
	*this = cpy;
}

// Surcharge d'opérateur
Animal	&Animal::operator=(const Animal &cpy)
{
	std::cout << "Assignation operator from Animal class called" << std::endl;
	if (this != &cpy)
		this->type = cpy.type;
	return (*this);
}

// Getters
const std::string	&Animal::getType() const
{
	std::cout << "Getter from Animal class called" << std::endl;
	return (this->type);
}

// Destructeurs
Animal::~Animal()
{
	std::cout << "Destructor from Animal class called" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, const Animal &animal)
{
	os << animal.lastIdea();
	return (os);
}

std::ostream	&operator<<(std::ostream &os, Animal &animal)
{
	os << animal.lastIdea();
	return (os);
}
