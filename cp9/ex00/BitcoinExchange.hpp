/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:57:54 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/16 16:10:08 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
	private:
		static std::map<std::string, float>	*_change;
		static const int daysInMonth[];

		// Constructeur
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);

		// Surcharge d'operateur
		BitcoinExchange					&operator=(const BitcoinExchange &cpy);

	public:
		// Fonctions membres
		static const BitcoinExchange	*getInstance();

		// Destructeur
		~BitcoinExchange();
};

#endif