/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:57:54 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/27 10:11:24 by eslamber         ###   ########.fr       */
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

		// Constructeur
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);

		// Surcharge d'operateur
		BitcoinExchange					&operator=(const BitcoinExchange &cpy);

	public:
		// Fonctions membres
		static const BitcoinExchange	*getInstance();
		static void						printChange(const std::string &file);

		// Destructeur
		~BitcoinExchange();
};

#endif