/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:42:43 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/23 09:51:53 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int			val;
		const int	static_value;

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
}

#endif