/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:33:42 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/02 16:14:19 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "SData.hpp"
# include <inttypes.h>

class Serializer
{
	private:
		// Constructeur
		Serializer();
		Serializer(const Serializer &cpy);

		// Surcharge d'operateur
		Serializer	&operator=(const Serializer &cpy);

		// Destructeur
		~Serializer();
	
	public:
		// Fonctions membres
		static uintptr_t	serialize(SData *ptr);
		static SData		*deserialize(uintptr_t raw);
};

#endif