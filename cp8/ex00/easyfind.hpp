/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:06:53 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/24 10:29:57 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T cont, int &elem)
{
	typename T::iterator	found;

	found = std::find(cont.begin(), cont.end(), elem);
	if (found == cont.end())
		throw std::out_of_range("Element not in container");
	return (found);
}

template <typename T>
const typename T::iterator	easyfind(const T cont, const int &elem)
{
	typename T::iterator	found;

	found = std::find(cont.begin(), cont.end(), elem);
	if (found == cont.end())
		throw std::out_of_range("Element not in container");
	return (found);
}

#endif