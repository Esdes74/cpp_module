/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:57:21 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/06 18:59:42 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

// Constructeur
BitcoinExchange::BitcoinExchange()
{
	_change = new std::map<std::string, float>;
}

// Getter
std::map<std::string, float>	&BitcoinExchange::getChange()
{
	return (*_change);
}

// Fonctions membres
const BitcoinExchange	*BitcoinExchange::getInstance()
{
	std::string	line;
	std::string	date;
	std::string	value;
	float		f;

	getChange().clear();
	static BitcoinExchange	neww;

	std::ifstream	file("cpp_09_data/data.csv");
	if (!file.is_open())
		throw std::ifstream::failure("Error : Fail when opening file");
	while (std::getline(file, line))
	{
		std::istringstream	str(line);
		if (std::getline(str, date, ',') && std::getline(str, value, ','))
		{
			str >> f;
			getChange().insert(std::make_pair(date, value));
		}
		else
			throw std::ifstream::failure("Error : Wrong line format");
	}
	return (&neww);
}

// Destructeur
BitcoinExchange::~BitcoinExchange()
{
	delete _change;
}
