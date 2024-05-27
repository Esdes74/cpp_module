/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:31:58 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/16 10:33:34 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed c( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	std::cout << (a < c) << std::endl;
	std::cout << (a <= c) << std::endl;
	std::cout << (c > a) << std::endl;
	std::cout << (c >= a) << std::endl;
	std::cout << (a != c) << std::endl;
	std::cout << (a == c) << std::endl;

	return 0;
}
