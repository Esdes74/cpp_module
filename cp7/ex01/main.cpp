// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.cpp                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/05/02 19:07:05 by eslamber          #+#    #+#             */
// /*   Updated: 2024/06/19 10:41:56 by eslamber         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>
#include <cstring>

// static std::string	print(std::string &str)
// {
// 	std::cout << str << std::endl;
// 	return (str);
// }

static const std::string	print(const std::string &str)
{
	std::cout << str << std::endl;
	return (str);
}

static std::string	add(std::string &str)
{
	str[0] = str[0] + 5;
	return (str);
}

int	main()
{
	// Premier test
	std::cout << "------------------ Test 1 ---------------------" << std::endl;
	std::string	test1[3] = {"Bonjour", "je m'appel", "Gestrude"};

	iter(test1, 3, print);

	// Deuxieme test
	std::cout << std::endl << "------------------ Test 2 ---------------------" << std::endl;
	std::string	test2[3] = {"Bonjour", "je m'appel", "Gestrude"};

	iter(test2, 3, add);
	iter(test2, 3, print);

	// Troisieme test
	std::cout << std::endl << "------------------ Test 3 ---------------------" << std::endl;
	const std::string	test3[3] = {"Bonjour", "je m'appel", "Gestrude"};

	iter(test3, 3, print);
	return (0);
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }
