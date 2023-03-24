/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:51:52 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/24 20:30:32 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
using namespace std;

class Fixed
{
	private:
		int					val;
		static const int	frac;

	public:
		// Constructeurs
		Fixed();
		Fixed(const int &raw);
		Fixed(float raw);
		Fixed(const Fixed &f);

		// Surcharge de l'opérateur
		Fixed	&operator=(const Fixed &f);

		bool	operator<(const Fixed &f) const;
		bool	operator>(const Fixed &f) const;
		bool	operator<=(const Fixed &f) const;
		bool	operator>=(const Fixed &f) const;
		bool	operator==(const Fixed &f) const;
		bool	operator!=(const Fixed &f) const;

		Fixed	operator+(const Fixed &f) const;
		Fixed	operator-(const Fixed &f) const;
		Fixed	operator*(const Fixed &f) const;
		Fixed	operator/(const Fixed &f) const;

		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		friend ostream	&operator<<(ostream &os, const Fixed &f);

		// Fonctions membres
		int		getRawBits() const;
		void	setRawBits(const int raw);
		float	toFloat() const;
		int		toInt() const;

		static Fixed		&min(Fixed &f, Fixed &s);
		static Fixed		&max(Fixed &f, Fixed &s);
		static const Fixed	&min(const Fixed &f, const Fixed &s);
		static const Fixed	&max(const Fixed &f, const Fixed &s);

		// Destructeur
		~Fixed();
};

#endif
