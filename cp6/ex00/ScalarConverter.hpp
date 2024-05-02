/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:01:15 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/02 11:19:47 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cctype>
# include <limits>
# include <sstream>

class ScalarConverter
{
	private:
		// Constructeur
		ScalarConverter();
		ScalarConverter(const ScalarConverter &cpy);

		// Surcharge d'opérateur
		ScalarConverter	&operator=(const ScalarConverter &cpy);

		// Destructeur
		~ScalarConverter();

	public:
		// Fonctions membres
		static void	convert(const std::string &str);
};

#endif