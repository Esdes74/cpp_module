/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:29:27 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/24 15:18:03 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructeur
Cat::Cat()
{
	std::cout << "Constructeur par defaut de la classe Cat appelé" << std::endl;
	this->type = "cat";
	this->brain = new Brain();
	this->max_idea = 0;
	this->brain->putIdea(0, "chasser");
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
void	Cat::makeSound(void) const
{
	std::cout << "Miiiiaaaou !!" << std::endl;
}

void	Cat::putIdea(const std::string idea)
{
	if (max_idea == 100)
		max_idea = 0;
	this->brain->putIdea(max_idea, idea);
	max_idea++;
}

std::string	Cat::lastIdea(void) const
{
	if (max_idea == 0 && this->brain->getIdeaNB(99) == "")
		return (this->brain->getIdeaNB(max_idea));
	else if (max_idea == 0 && this->brain->getIdeaNB(99) != "")
		return (this->brain->getIdeaNB(99));
	else
		return (this->brain->getIdeaNB(max_idea - 1));
}

// Destructeur
Cat::~Cat()
{
	std::cout << "Destructeur de la classe Cat appelé" << std::endl;
	delete this->brain;
}

std::ostream	&operator<<(std::ostream &os, const Cat &cat)
{
	os << cat.lastIdea();
	return (os);
}
