/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:57:21 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/16 17:14:22 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

const int BitcoinExchange::daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

static void	make_map(std::map<std::string, float> &mymap, char sep);
static void	verif_line(const std::map<std::string, float>::iterator &myline, int mod);

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
	std::map<std::string, float>::iterator	it;

	if (_change != 0)
		_change->clear();
	static BitcoinExchange	neww;
	make_map(*_change, ',');
	it = _change->begin();
	do
		verif_line(it++, 0);
	while (it != _change->end());
	return (&neww);
}

// Destructeur
BitcoinExchange::~BitcoinExchange()
{
	delete _change;
}

static void	make_map(std::map<std::string, float> &mymap, char sep)
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
		if (line != "date,exchange_rate" && line != "date | value")
		{
			std::istringstream	str(line);
			if (std::getline(str, date, sep) && std::getline(str, value, sep))
			{
				std::istringstream	v(value);
				v >> f;
				mymap.insert(std::make_pair(date, f));
			}
			else
				throw std::ifstream::failure("Error : Wrong line format");
		}
	}
}

static void	verif_line(const std::map<std::string, float>::iterator &myline, int mod)
{
	std::string	year_str;
	std::string	month_str;
	std::string	day_str;
	int			year;
	int			month;
	int			day;

	if (myline->second < 0 || (myline->second > 1000 && mod == 1))
	{
		if (mod == 1)
			throw std::out_of_range("Error : Value can't be negatif");
		throw std::out_of_range("Error : Value not in range [0, 1000]");
	}

	std::istringstream	date(myline->first);
	if (!std::getline(date, year_str, '-') || !std::getline(date, month_str, '-') || !std::getline(date, day_str, '-'))
	{
        std::cerr << "Error parsing date string: " << myline->first << std::endl;
        std::cerr << "Parsed values: year=" << year_str << ", month=" << month_str << ", day=" << day_str << std::endl;
		throw std::ifstream::failure("Error : Wrong line format");
	}
	year = std::stoi(year_str);
	month = std::stoi(month_str);
	day = std::stoi(day_str);
}
