/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:34:10 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/02 15:59:53 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Constructeur
Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &cpy)
{
	(void) cpy;
}

// Surcharge d'operateur
Serializer	&Serializer::operator=(const Serializer &cpy)
{
	(void) cpy;
	return (*this);
}

// Fonctions membres
uintptr_t	Serializer::serialize(SData *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

SData		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<SData*>(raw));
}

// Destructeur
Serializer::~Serializer()
{
}
