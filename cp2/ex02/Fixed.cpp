/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:42:54 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/26 15:09:21 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static float round(const float nb);

// Constructeurs
Fixed::Fixed(void)
{
	this->val = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::Fixed(const int val)
{
	this->val = val << this->bits;
}

Fixed::Fixed(const float val)
{
	this->val = round(val * (1 << this->bits));
}

// Surcharge d'opérateurs
Fixed	&Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->val = fixed.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator<(const Fixed &fixed)
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>(const Fixed &fixed)
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator==(const Fixed &fixed)
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(const Fixed &fixed)
{
	return (this->toFloat() != fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed &fixed)
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator>=(const Fixed &fixed)
{
	return (this->toFloat() >= fixed.toFloat());
}

Fixed	&Fixed::operator+(const Fixed &fixed)
{
	Fixed tmp((this->toFloat() + fixed.toFloat()));
	*this = tmp;
	return (*this);
}

Fixed	&Fixed::operator-(const Fixed &fixed)
{
	Fixed tmp((this->toFloat() - fixed.toFloat()));
	*this = tmp;
	return (*this);
}

Fixed	&Fixed::operator*(const Fixed &fixed)
{
	Fixed tmp((this->toFloat() * fixed.toFloat()));
	*this = tmp;
	return (*this);
}

Fixed	&Fixed::operator/(const Fixed &fixed)
{
	Fixed tmp((this->toFloat() / fixed.toFloat()));
	*this = tmp;
	return (*this);
}

Fixed	&Fixed::operator++(void)
{
	this->val++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->val--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	tmp.val = this->val++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	tmp.val = this->val--;
	return (tmp);
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

Fixed	&Fixed::min(Fixed &x, Fixed &y)
{
	if (x.toFloat() < y.toFloat())
		return (x);
	return (y);
}

Fixed	&Fixed::max(Fixed &x, Fixed &y)
{
	if (x.toFloat() < y.toFloat())
		return (y);
	return (x);
}

const Fixed	&Fixed::min(const Fixed &x, const Fixed &y)
{
	if (x.toFloat() < y.toFloat())
		return (x);
	return (y);
}

const Fixed	&Fixed::max(const Fixed &x, const Fixed &y)
{
	if (x.toFloat() < y.toFloat())
		return (y);
	return (x);
}

// Destructeurs
Fixed::~Fixed(void)
{
}

// Fonctions statiques
static float round(const float nb)
{
	return ((nb > 0.0) ? floor(nb + 0.5) : ceil(nb - 0.5));
}