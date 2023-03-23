/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:51:35 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/23 14:07:40 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::frac = 8;

Fixed::Fixed()
{
	cout << "Default constructor called\n";
	val = 0;
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

int		Fixed::getRawBits() const
{
	cout << "GetRawBits member function called\n";
	return (this->val);
}

void	Fixed::setRawBits(const int raw)
{
	(void) raw;
	cout << "SetRawBits member function called\n";
	this->val = raw;
}

Fixed::~Fixed()
{
	cout << "Destructor called\n";
}
