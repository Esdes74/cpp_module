/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:42:43 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/26 15:09:21 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					val;
		static const int	bits = 8;

	public:
		// Constructeurs
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int val);
		Fixed(const float val);

		// Surcharge d'opérateurs
		Fixed	&operator=(const Fixed &fixed);

		// Fonctions membre
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// Destructeur
		~Fixed();
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);


#endif