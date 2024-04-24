/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:20:58 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/23 20:22:44 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructeur
Dog::Dog()
{
	std::cout << "Constructeur par défaut de la classe Dog appelé" << std::endl;
	this->type = "dog";
	this->brain = new Brain();
	this->max_idea = 0;
	this->brain->putIdea(0, "");
	this->brain->putIdea(99, "");
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
	{
		Animal::operator=(cpy);
		delete this->brain;
		this->brain = NULL;
		this->brain = new Brain(*cpy.brain);
		this->max_idea = cpy.max_idea;
	}
	return (*this);
}

// Fonctions membres
void	Dog::makeSound(void) const
{
	std::cout << "WAAf waaaf" << std::endl;
}

void	Dog::putIdea(const std::string idea)
{
	if (max_idea == 100)
		max_idea = 0;
	this->brain->putIdea(max_idea, idea);
	max_idea++;
}

std::string	Dog::lastIdea(void) const
{
	if (max_idea == 0 && this->brain->getIdeaNB(99) == "")
		return (this->brain->getIdeaNB(max_idea));
	else if (max_idea == 0 && this->brain->getIdeaNB(99) != "")
		return (this->brain->getIdeaNB(99));
	else
		return (this->brain->getIdeaNB(max_idea - 1));
}

// Destructeur
Dog::~Dog()
{
	std::cout << "Destructeur de la classe Dog appelé" << std::endl;
	delete this->brain;
}

std::ostream	&operator<<(std::ostream &os, const Dog &dog)
{
	os << dog.lastIdea();
	return (os);
}
