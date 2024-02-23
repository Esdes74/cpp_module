/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:42:43 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/23 13:27:07 by eslamber         ###   ########.fr       */
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
		static const int	static_value = 8;

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