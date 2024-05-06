/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:57:21 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/06 12:48:14 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructeur
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	(void) cpy;
}

// Surcharge d'operateur
BitcoinExchange			&BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	(void) cpy;
	return (*this);
}

// Fonctions membres
static BitcoinExchange	&BitcoinExchange::getInstance();

// Destructeur
BitcoinExchange::~BitcoinExchange()
{
}
