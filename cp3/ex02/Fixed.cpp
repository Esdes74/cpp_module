/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:51:35 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/24 15:08:06 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::frac = 8;

// Constructors
Fixed::Fixed()
{
	cout << "Default constructor called\n";
	val = 0;
}

Fixed::Fixed(const int &raw)
{
	cout << "Int constructor called\n";
	val = raw << this->frac;
}

Fixed::Fixed(float raw)
{
	cout << "Float constructor called\n";
	val = roundf(raw * (1 << frac));
}

Fixed::Fixed(const Fixed &f)
{
	cout << "Copy constructor called\n";
	*this = f;
}

// Surcharges d'opérateurs
Fixed	&Fixed::operator=(const Fixed &f)
{
	cout << "Copy assignement operator called\n";
	if (this != &f)
		this->val = f.getRawBits();
	return (*this);
}

ostream	&operator<<(ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}

bool	Fixed::operator<(const Fixed &f) const
{
	return (val < f.val);
}

bool	Fixed::operator>(const Fixed &f) const
{
	return (val > f.val);
}

bool	Fixed::operator<=(const Fixed &f) const
{
	return (val <= f.val);
}

bool	Fixed::operator>=(const Fixed &f) const
{
	return (val >= f.val);
}

bool	Fixed::operator==(const Fixed &f) const
{
	return (val == f.val);
}

bool	Fixed::operator!=(const Fixed &f) const
{
	return (val != f.val);
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	Fixed	res;

	res = this->val + f.val;
	return (res);
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	Fixed	res;

	res = this->val - f.val;
	return (res);
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	Fixed	res;

	res = this->val * f.val;
	return (res);
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	Fixed	res;

	res = this->val / f.val;
	return (res);
}

Fixed	&Fixed::operator++()
{
	val++;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	val--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	save(*this);

	val++;
	return (save);
}

Fixed	Fixed::operator--(int)
{
	Fixed	save(*this);

	val--;
	return (save);
}

// Fonctions membres
int		Fixed::getRawBits() const
{
	cout << "GetRawBits member function called\n";
	return (this->val);
}

void	Fixed::setRawBits(const int raw)
{
	cout << "SetRawBits member function called\n";
	this->val = raw;
}

float	Fixed::toFloat() const
{
	return ((float) val / (1 << frac));
}

int	Fixed::toInt() const
{
	return (val >> frac);
}

Fixed	&Fixed::min(Fixed &f, Fixed &s)
{
	if (f < s)
		return (f);
	return (s);
}

Fixed	&Fixed::max(Fixed &f, Fixed &s)
{
	if (f < s)
		return (s);
	return (f);
}

const Fixed	&Fixed::min(const Fixed &f, const Fixed &s)
{
	if (f < s)
		return (f);
	return (s);
}

const Fixed	&Fixed::max(const Fixed &f, const Fixed &s)
{
	if (f < s)
		return (s);
	return (f);
}

// Destructors
Fixed::~Fixed()
{
	cout << "Destructor called\n";
}
