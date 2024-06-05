/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:00:29 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/05 16:01:14 by eslamber         ###   ########.fr       */
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
		this->_stk = cpy._stk;
	}
	return (*this);
}

// Fonctions membres
void	RPN::pushNumber(int nb)
{
	_stk.push(nb);
}

void	RPN::addNumber()
{
	int	a;
	int	b;

	if (_stk.size() < 2)
		throw std::out_of_range("Error: not enought numbers");
	a = _stk.top();
	_stk.pop();
	b = _stk.top();
	_stk.pop();
	_stk.push(a + b);
}

void	RPN::mulNumber()
{
	int	a;
	int	b;

	if (_stk.size() < 2)
		throw std::out_of_range("Error: not enought numbers");
	a = _stk.top();
	_stk.pop();
	b = _stk.top();
	_stk.pop();
	_stk.push(a * b);
}

void	RPN::divNumber()
{
	int	a;
	int	b;

	if (_stk.size() < 2)
		throw std::out_of_range("Error: not enought numbers");
	a = _stk.top();
	_stk.pop();
	b = _stk.top();
	_stk.pop();
	_stk.push(a / b);
}

void	RPN::susNumber()
{
	int	a;
	int	b;

	if (_stk.size() < 2)
		throw std::out_of_range("Error: not enought numbers");
	a = _stk.top();
	_stk.pop();
	b = _stk.top();
	_stk.pop();
	_stk.push(a - b);
}

void	RPN::printRes()
{
	int	res;

	if (_stk.size() != 1)
		throw std::out_of_range("Error: mot enought operands");
	res = _stk.top();
	_stk.pop();
	std::cout << res << std::endl;
}


// Destructeur
RPN::~RPN()
{
}
