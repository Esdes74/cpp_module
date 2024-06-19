/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:07:16 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/19 12:24:43 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename F, typename R>
void	iter(T *array, size_t len, R func(const F))
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		func(array[i]);
		i++;
	}
}

template <typename T, typename F, typename R>
void	iter(const T *array, size_t len, const R func(const F))
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		func(array[i]);
		i++;
	}
}

#endif