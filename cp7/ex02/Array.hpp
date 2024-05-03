/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:07:56 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/03 16:25:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <stdexcept>
# include <iostream>

template <typename T>
class Array
{
	private:
		T		*_array;
		size_t	_size;

	public:
		// Constructeurs
		Array()
			:_array(new T[0]), _size(0)
		{
			_array[0] = 0;
		}

		Array(const size_t &n)
			:_array(new T[n]), _size(n) {};
		// {
		// 	size_t	i;

		// 	i = 0;
		// 	while (i < n)
		// 	{
		// 		_array[i] = 0;
		// 		i++;
		// 	}
		// }

		Array(const Array &cpy)
		{
			*this = cpy;
		}

		// Surcharge d'opérateur
		Array	&operator=(const Array &cpy)
		{
			size_t	i;

			if (this != &cpy)
			{
				_size = cpy.size();
				delete[] _array;
				_array = new T[_size];
				i = 0;
				while (i < _size)
				{
					_array[i] = cpy._array[i];
					i++;
				}
			}
			return (*this);
		}

		T		&operator[](const size_t &ind)
		{
			if (_size < ind)
				throw std::out_of_range("Index out of range");
			return (_array[ind]);
		}

		// Fonctions membres
		size_t	size() const
		{
			return (_size);
		}

		// Destructeur
		~Array()
		{
			delete[] _array;
		}
};

#endif