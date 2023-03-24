/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:51:35 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/24 13:48:11 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::frac = 8;

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

Fixed::~Fixed()
{
	cout << "Destructor called\n";
}
