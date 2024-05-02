/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:06:41 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/02 19:25:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T	swp;

	swp = a;
	a = b;
	b = swp;
}

template <typename T>
T	&min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T	&max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif