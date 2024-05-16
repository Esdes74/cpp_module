/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:42:43 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/16 09:25:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>
# include <iostream>

class Fixed
{
	private:
		int					val;
		static const int	bits;

	public:
		// Constructeurs
		Fixed();
		Fixed(const Fixed &fixed);

		// Surcharge d'opérateurs
		Fixed	&operator=(const Fixed &fixed);

		// Fonctions membre
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		// Destructeur
		~Fixed();
};

#endif