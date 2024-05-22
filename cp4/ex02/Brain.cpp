/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:30:36 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/22 10:49:40 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	size_t	i;

	std::cout << "Default constructor from Dog class called" << std::endl;
	this->ideas = new std::string[100];
	i = 0;
	while (i < 100)
		this->ideas[i++] = "";
}

Brain::Brain(const Brain &cpy)
{
	std::cout << "Copy constructor from Dog class called" << std::endl;
	// int	i;

	if (this != &cpy)
	{
		this->ideas = new std::string[100];
		*this = cpy;
	}
	// i = 0;
	// while (i < 100)
	// {
	// 	this->ideas[i] = cpy.ideas[i];
	// 	i++;
	// }
}

// Surcharge d'opérateur
Brain	&Brain::operator=(const Brain &cpy)
{
	std::cout << "Assignation operator from Dog class called" << std::endl;
	int	i;

	i = 0;
	while (i < 100)
	{
		this->ideas[i] = cpy.ideas[i];
		i++;
	}
	return (*this);
}

// Fonction membre
std::string	Brain::getIdeaNB(const int nb) const
{
	return (this->ideas[nb]);
}

void	Brain::putIdea(const int nb, const std::string idea)
{
	this->ideas[nb] = idea;
}

// Destructeur
Brain::~Brain()
{
	std::cout << "Destructor from Dog class called" << std::endl;
	delete[] ideas;
}
