/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:51:52 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/23 13:55:11 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
using namespace std;

class Fixed
{
	private:
		int					val;
		static const int	frac;

	public:
		// Constructeurs
		Fixed();
		Fixed(const Fixed &f);

		// Surcharge de l'opérateur
		Fixed	&operator=(const Fixed &f);

		// Fonctions membres
		int		getRawBits() const;
		void	setRawBits(const int raw);

		// Destructeur
		~Fixed();
};

#endif
