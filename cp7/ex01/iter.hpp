/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:07:16 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/02 20:07:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T>
void	iter(T *array, size_t len, int func(const T&))
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		array[i] = func(array[i]);
		i++;
	}
}

#endif