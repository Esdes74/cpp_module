/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:51:52 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/24 13:39:34 by eslamber         ###   ########.fr       */
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
		friend ostream	&operator<<(ostream &os, const Fixed &f);

		// Fonctions membres
		int		getRawBits() const;
		void	setRawBits(const int raw);
		float	toFloat() const;
		int		toInt() const;

		// Destructeur
		~Fixed();
};

#endif
