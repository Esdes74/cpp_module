/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:46:51 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/05 11:02:29 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <cstddef>

class Span
{
	private:
		size_t				_size;
		std::vector<int>	_list;

		// Constructeur
		Span();
	
	public:
		// Constructeur
		Span(const Span &cpy);
		Span(const size_t &n);

		// Surcharge d'opérateur
		Span	&operator=(const Span &cpy);

		// Fonctions membres
		void	addNumber(const int &neww);
		int		shortestSpan() const;
		int		longestSpan() const;

		// Destructeur
		~Span();
};

#endif