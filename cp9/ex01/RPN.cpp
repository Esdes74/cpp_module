/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:00:29 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/06 12:00:39 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

// Constructeur
RPN::RPN()
{
}

RPN::RPN(const RPN &cpy)
{
	*this = cpy;
}

// Surcharge d'operateur
RPN		&RPN::operator=(const RPN &cpy) // TODO: vérifier que la copie soit bien une copie profonde
{
	if (this != &cpy)
	{
		this->stk = cpy.stk;
	}
	return (*this);
}

// Fonctions membres
void	RPN::pushNumber(int nb)
{
	stk.push(nb);
}

void	RPN::addNumber()
{
	int	a;
	int	b;

	if (stk.size() < 2)
		throw std::out_of_range("Error: not enought numbers");
	a = stk.top();
	stk.pop();
	b = stk.top();
	stk.pop();
	stk.push(b + a);
}

void	RPN::mulNumber()
{
	int	a;
	int	b;

	if (stk.size() < 2)
		throw std::out_of_range("Error: not enought numbers");
	a = stk.top();
	stk.pop();
	b = stk.top();
	stk.pop();
	stk.push(b * a);
}

void	RPN::divNumber()
{
	int	a;
	int	b;

	if (stk.size() < 2)
		throw std::out_of_range("Error: not enought numbers");
	a = stk.top();
	stk.pop();
	b = stk.top();
	stk.pop();
	stk.push(b / a);
}

void	RPN::susNumber()
{
	int	a;
	int	b;

	if (stk.size() < 2)
		throw std::out_of_range("Error: not enought numbers");
	a = stk.top();
	stk.pop();
	b = stk.top();
	stk.pop();
	stk.push(b - a);
}

void	RPN::printRes()
{
	int	res;

	if (stk.size() != 1)
		throw std::out_of_range("Error: bad arguments");
	res = stk.top();
	stk.pop();
	std::cout << res << std::endl;
}


// Destructeur
RPN::~RPN()
{
}
