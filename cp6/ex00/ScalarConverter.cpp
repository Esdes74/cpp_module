/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:01:15 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/02 12:27:57 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	printChar(const std::string &str);
static void	printInt(const std::string &str);
static void	printDouble(const std::string &str);
static void	printFloat(const std::string &str);
static int	checkDoubleOrFloat(const std::string &str);
static int	checkInt(const std::string &str);
static bool	checkChar(const std::string &str);
static bool	checkException(const std::string &str);

// Constructeur
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	(void)	cpy;
}

// Surcharge d'opérateur
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &cpy)
{
	(void)	cpy;
	return (*this);
}

// Fonctions membres
void	ScalarConverter::convert(const std::string &str)
{
	int	ck_float;
	int	ck_int;

	ck_float = checkDoubleOrFloat(str);
	ck_int = checkInt(str);
	if (checkChar(str))
		printChar(str);
	else if (ck_float == 0 && ck_int == 1)
		printInt(str);
	else if (ck_float == 1)
		printDouble(str);
	else if (ck_float == 2)
		printFloat(str);
	else if (checkException(str))
		return ;
	else if (ck_float == 3 || ck_int == 2)
		std::cout << "Wrong litteral\n";
}

// Destructeur
ScalarConverter::~ScalarConverter()
{
}

// Static
static void	printChar(const std::string &str)
{
	std::cout << "char: " << str[0] << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}

static void	printInt(const std::string &str)
{
	long long			val;
	std::istringstream	printv(str);
	
	printv >> val;
	if (std::isprint(static_cast<char>(val)))
		std::cout << "char : " << static_cast<char>(val) << std::endl;
	else
		std::cout << "char : " << "impossible" << std::endl;
	if (val >= std::numeric_limits<int>::min() \
	&& val <= std::numeric_limits<int>::max())
		std::cout << "int : " << val << std::endl;
	else
		std::cout << "int : " << "impossible" << std::endl;
	if (val >= -1 * std::numeric_limits<float>::max() \
	&& val <= std::numeric_limits<float>::max())
		std::cout << "float : " << val << "f" << std::endl;
	else
		std::cout << "float : " << "impossible" << std::endl;
	if (val >= -1 * std::numeric_limits<double>::max() \
	&& val <= std::numeric_limits<double>::max())
		std::cout << "double : " << val << std::endl;
	else
		std::cout << "double : " << "impossible" << std::endl;
}

static void	printDouble(const std::string &str)
{
	long double			val;
	std::istringstream	printv(str);
	
	printv >> val;
	if (std::isprint(static_cast<char>(val)))
		std::cout << "char : " << static_cast<char>(val) << std::endl;
	else
		std::cout << "char : " << "impossible" << std::endl;
	if (val >= std::numeric_limits<int>::min() \
	&& val <= std::numeric_limits<int>::max())
		std::cout << "int : " << val << std::endl;
	else
		std::cout << "int : " << "impossible" << std::endl;
	if (val >= -1 * std::numeric_limits<float>::max() \
	&& val <= std::numeric_limits<float>::max())
		std::cout << "float : " << val << "f" << std::endl;
	else
		std::cout << "float : " << "impossible" << std::endl;
	if (val >= -1 * std::numeric_limits<double>::max() \
	&& val <= std::numeric_limits<double>::max())
		std::cout << "double : " << val << std::endl;
	else
		std::cout << "double : " << "impossible" << std::endl;
}

static void	printFloat(const std::string &str)
{
	double				val;
	std::istringstream	printv(str);

	printv >> val;
	if (std::isprint(static_cast<char>(val)))
		std::cout << "char : " << static_cast<char>(val) << std::endl;
	else
		std::cout << "char : " << "impossible" << std::endl;
	if (val >= std::numeric_limits<int>::min() \
	&& val <= std::numeric_limits<int>::max())
		std::cout << "int : " << val << std::endl;
	else
		std::cout << "int : " << "impossible" << std::endl;
	if (val >= -1 * std::numeric_limits<float>::max() \
	&& val <= std::numeric_limits<float>::max())
		std::cout << "float : " << val << "f" << std::endl;
	else
		std::cout << "float : " << "impossible" << std::endl;
	if (val >= -1 * std::numeric_limits<double>::max() \
	&& val <= std::numeric_limits<double>::max())
		std::cout << "double : " << val << std::endl;
	else
		std::cout << "double : " << "impossible" << std::endl;
}

// Retourne 0 si aucun des deux, 1 si double, 2 si float et 3 si problème
static int	checkDoubleOrFloat(const std::string &str)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
		{
			if (str[i] == '.' && ret == 0)
				ret++;
			else if (str[i] == 'f' && ret == 1)
				ret++;
			else if (!(i == 0 && (str[i] == '-' || str[i] == '+')))
				return (3);
		}
		i++;
	}
	return (ret);
}

// Retourne 0 si non int, 1 si int et 2 si probleme
static int	checkInt(const std::string &str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]) && i == 0 && str[i] != '-' && str[i] != '+')
			return (0);
		else if (!std::isdigit(str[i]) && i != 0)
		{
			if (str[i] == '.')
				return (0);
			return (2);
		}
		i++;
	}
	return (1);
}

// Retourne 0 si pas un char, 1 si un char et 2 si probleme
static bool	checkChar(const std::string &str)
{
	if (str.length() == 1 && std::isalpha(str[0]))
		return (true);
	return (false);
}

// Check toutes les exceptions et les imprimes
// retourne true si une exception est trouvé et false si non
static bool	checkException(const std::string &str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (true);
	}
	else if (str == "+inf" || str == "inf" \
	|| str == "inff" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return (true);
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (true);
	}
	return (false);
}
