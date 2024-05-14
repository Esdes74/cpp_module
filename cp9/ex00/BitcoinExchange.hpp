/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:57:54 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/06 18:53:26 by eslamber         ###   ########.fr       */
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

		// Getter
		static std::map<std::string, float>	&getChange();

	public:
		// Fonctions membres
		static const BitcoinExchange	*getInstance();

		// Destructeur
		~BitcoinExchange();
};

#endif