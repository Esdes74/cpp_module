/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:57:21 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/28 11:21:53 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

static void	make_map(std::multimap<std::string, float> &mymap, const std::string &file_name, char sep);
static void	verif_line(const std::pair<std::string, float> &myline, int mod);
static void	get_date_values(std::string date, int &year, int &month, int &day);

std::multimap<std::string, float>	*BitcoinExchange::_change = 0;

// Constructeur
BitcoinExchange::BitcoinExchange()
{
	if (_change == 0)
		_change = new std::multimap<std::string, float>;
}

// Fonctions membres
void	BitcoinExchange::initilize()
{
	std::multimap<std::string, float>::iterator	it;

	if (_change != 0)
		_change->clear();
	static BitcoinExchange	neww;
	make_map(*_change, "cpp_09_data/data.csv", ',');
	it = _change->begin();
	do
		verif_line(*(it++), 0);
	while (it != _change->end());
}

void	BitcoinExchange::printChange(const std::string &file_name)
{
	std::string						line;
	std::string						date;
	std::string						value;
	float							f;
	std::pair<std::string, float>	inputLine;

	std::ifstream	file(file_name);
	if (!file.is_open())
		throw std::ifstream::failure("Error : Fail when opening file");
	while (std::getline(file, line))
	{
		try
		{
			if (line != "date | value")
			{
				line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
				std::istringstream	str(line);
				if (std::getline(str, date, '|') && std::getline(str, value, '|'))
				{
					std::istringstream	v(value);
					v >> f;
					inputLine = std::make_pair(date, f);
				}
				else
					throw std::domain_error("¤¤ " + line + " -> Error : Wrong line format");
				verif_line(inputLine, 1);
				printLine(inputLine);
			}
		}
		catch (const std::exception &expt)
		{
			std::cerr << expt.what() << std::endl;
		}
	}
}

void	BitcoinExchange::printLine(const std::pair<std::string, float> &line)
{
	std::multimap<std::string, float>::iterator	it;

	it = _change->lower_bound(line.first);
	if (it != _change->begin())
		it--;
	std::cout << line.first << " => " << line.second << " = " << line.second * it->second << std::endl;
}

// Destructeur
BitcoinExchange::~BitcoinExchange()
{
	delete _change;
}

// Fonctions supplementaires
static void	make_map(std::multimap<std::string, float> &mymap, const std::string &file_name, char sep)
{
	std::string	line;
	std::string	date;
	std::string	value;
	float		f;

	std::ifstream	file(file_name);
	if (!file.is_open())
		throw std::ifstream::failure("Error : Fail when opening file");
	while (std::getline(file, line))
	{
		if (line != "date,exchange_rate" && line != "date | value")
		{
			line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
			std::istringstream	str(line);
			if (std::getline(str, date, sep) && std::getline(str, value, sep))
			{
				std::istringstream	v(value);
				v >> f;
				mymap.insert(std::make_pair(date, f));
			}
			else
				std::cerr << "¤¤ " << line << " -> " << "Error : Wrong line format" << std::endl;
		}
	}
}

static void	verif_line(const std::pair<std::string, float> &myline, int mod)
{
	int			year;
	int			month;
	int			day;
	const int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Verification que la value soit correcte selon le mod 
	// (0 pour le fichier de data et 1 pour l'input qui doit etre compris entre 0 et 1000)
	if (myline.second < 0 || (myline.second > 1000.0 && mod == 1))
	{
		std::cerr << "¤¤ " << myline.first << " : " << myline.second << " -> ";
		if (mod != 1)
			throw std::out_of_range("Error : Value can't be negatif");
		throw std::out_of_range("Error : Value not in range [0, 1000]");
	}

	// recuperation des valeurs de la date pour ensuite pouvoir les verifier
	get_date_values(myline.first, year, month, day);
	if (year < 0 || year > 2024)
	{
		std::cerr << "¤¤ " << myline.first << " : " << myline.second << " -> ";
		throw std::out_of_range("Error : Year not in range [0, 2024]");
	}
	if (month < 1 || month > 12)
	{
		std::cerr << "¤¤ " << myline.first << " : " << myline.second << " -> ";
		throw std::out_of_range("Error : Month not in range [1, 12]");
	}
	if (day < 0 || day > daysInMonth[month - 1])
	{
		if (day == 29 && month == 2 && year % 4 == 0 && ((year % 100 != 0) || (year % 400 == 0)))
			return ;
		std::cerr << "¤¤ " << myline.first << " : " << myline.second << " -> ";
		if (day == 29 && month == 2)
			throw std::out_of_range("Error : Invalid day not a leap year");
		throw std::out_of_range("Error : Invalid day");
	}
}

static void	get_date_values(std::string line, int &year, int &month, int &day)
{
	std::string	year_str;
	std::string	month_str;
	std::string	day_str;

	std::istringstream	date(line);
	if (!std::getline(date, year_str, '-') || !std::getline(date, month_str, '-') || !std::getline(date, day_str, '-'))
		throw std::ifstream::failure("¤¤ " + line + " -> Error : Wrong date format");
	year = std::stoi(year_str);
	month = std::stoi(month_str);
	day = std::stoi(day_str);
}
