/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:42:54 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/16 09:26:08 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::bits = 8;

// Constructeurs
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->val = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

// Surcharge d'opérateurs
Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->val = fixed.getRawBits();
	return (*this);
}

// Fonctions membres
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->val);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->val = raw;
}

// Destructeurs
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}