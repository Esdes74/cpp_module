/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:42:54 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/16 09:27:03 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static float	round(const float nb);

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

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	this->val = val << this->bits;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	this->val = round(val * (1 << this->bits));
}

// Surcharge d'opérateurs
Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->val = fixed.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

// Fonctions membres
int		Fixed::getRawBits(void) const
{
	return (this->val);
}

void	Fixed::setRawBits(int const raw)
{
	this->val = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float) this->getRawBits() / (1 << this->bits));
}

int		Fixed::toInt(void) const
{
	return ((int) this->val >> this->bits);
}

// Destructeurs
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Fonctions statiques
static float round(const float nb)
{
	return ((nb > 0.0) ? floor(nb + 0.5) : ceil(nb - 0.5));
}