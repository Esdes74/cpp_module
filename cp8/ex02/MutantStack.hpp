/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:07:01 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/24 11:40:55 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
// # include <map>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		// Typedef de l'itérateur pour simplifier l'écriture et la réception d'iterateur
		typedef	typename std::stack<T>::container_type::iterator iterator;
		typedef	typename std::stack<T>::container_type::const_iterator const_iterator;

		// Constructeur
		MutantStack() {};
		MutantStack(const MutantStack &cpy)
		{
			*this = cpy;
		}

		// Surcharge d'operateur
		MutantStack									&operator=(const MutantStack &cpy)
		{
			this->c = cpy.c;
			return (*this);
		}

		// Fonctions membres
		iterator		begin()
		{
			return (this->c.begin());
		}

		const_iterator	begin() const
		{
			return (this->c.begin());
		}

		iterator		end()
		{
			return (this->c.end());
		}

		const_iterator	end() const
		{
			return (this->c.end());
		}

		// Destructeur
		~MutantStack() {};
};

#endif