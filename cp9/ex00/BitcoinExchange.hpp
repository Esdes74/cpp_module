/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:57:54 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/28 11:20:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
	private:
		static std::multimap<std::string, float>	*_change;

		// Constructeur
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);

		// Surcharge d'operateur
		BitcoinExchange	&operator=(const BitcoinExchange &cpy);

		// Fonctions membres
		static void		printLine(const std::pair<std::string, float> &line);

	public:
		// Fonctions membres
		static void		initilize();
		static void		printChange(const std::string &file);

		// Destructeur
		~BitcoinExchange();
};

#endif