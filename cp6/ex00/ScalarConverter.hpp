/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:01:15 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/18 13:14:24 by eslamber         ###   ########.fr       */
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

template <typename T>
void	printNB(const T &val)
{
	if (val <= 255 && val >= 0 && std::isprint(val))
		std::cout << "char : " << static_cast<char>(val) << std::endl;
	else
		std::cout << "char : " << "impossible" << std::endl;
	if (val >= std::numeric_limits<int>::min() \
	&& val <= std::numeric_limits<int>::max())
		std::cout << "int : " << static_cast<int>(val) << std::endl;
	else
		std::cout << "int : " << "impossible" << std::endl;
	if (val >= -1 * std::numeric_limits<float>::max() \
	&& val <= std::numeric_limits<float>::max())
		std::cout << "float : " << static_cast<float>(val) << "f" << std::endl;
	else
		std::cout << "float : " << "impossible" << std::endl;
	if (val >= -1 * std::numeric_limits<double>::max() \
	&& val <= std::numeric_limits<double>::max())
		std::cout << "double : " << static_cast<double>(val) << std::endl;
	else
		std::cout << "double : " << "impossible" << std::endl;
}

#endif