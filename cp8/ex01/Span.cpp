/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:46:34 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/05 11:26:11 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iostream>

// Constructeur
Span::Span()
{
}

Span::Span(const Span &cpy)
{
	*this = cpy;
}

Span::Span(const size_t &n)
	:_size(n)
{
}

// Surcharge d'opérateur
Span	&Span::operator=(const Span &cpy)
{
	if (this != &cpy)
	{
		_size = cpy._size;
		_list = cpy._list;
	}
	return (*this);
}

// Fonctions membres
void	Span::addNumber(const int &neww)
{
	if (_list.size() >= _size)
		throw std::out_of_range("Span full");
	_list.push_back(neww);
}

void	Span::addNumber(int start, int end)
{
	while (start < end)
	{
		addNumber(start);
		start++;
	}
}

int		Span::shortestSpan() const
{
	std::vector<int>	tmp;
	int					ret;
	size_t				i;

	if (_list.size() < 2)
		throw std::logic_error("Not enought elements in Span to apply shortest");
	tmp = _list;
	std::sort(tmp.begin(), tmp.end());
	ret = tmp[1] - tmp[0];
	i = 0;
	while (++i < _list.size() - 1)
		if (ret > tmp[i + 1] - tmp[i])
			ret = tmp[i + 1] - tmp[i];
	return (ret);
}

int		Span::longestSpan() const
{
	int	max;
	int	min;

	if (_list.size() < 2)
		throw std::logic_error("Not enought elements in Span to apply longest");
	max = *std::max_element(_list.begin(), _list.end());
	min = *std::min_element(_list.begin(), _list.end());
	return (max - min);
}

// Destructeur
Span::~Span()
{
}
