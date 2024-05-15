/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:57:21 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/15 16:53:11 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

static void	make_map(std::map<std::string, float> &mymap);

std::map<std::string, float>	*BitcoinExchange::_change = 0;

// Constructeur
BitcoinExchange::BitcoinExchange()
{
	if (_change == 0)
		_change = new std::map<std::string, float>;
}

// Fonctions membres
const BitcoinExchange	*BitcoinExchange::getInstance()
{
	if (_change != 0)
		_change->clear();
	static BitcoinExchange	neww;
	make_map(*_change);
	return (&neww);
}

// Destructeur
BitcoinExchange::~BitcoinExchange()
{
	delete _change;
}

static void	make_map(std::map<std::string, float> &mymap)
{
	std::string	line;
	std::string	date;
	std::string	value;
	float		f;

	std::ifstream	file("cpp_09_data/data.csv");
	if (!file.is_open())
		throw std::ifstream::failure("Error : Fail when opening file");
	while (std::getline(file, line))
	{
		std::istringstream	str(line);
		if (std::getline(str, date, ',') && std::getline(str, value, ','))
		{
			std::istringstream	v(value);
			v >> f;
			mymap.insert(std::make_pair(date, f));
		}
		else
			throw std::ifstream::failure("Error : Wrong line format");
	}
}
