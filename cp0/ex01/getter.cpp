/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:24:38 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/16 18:31:37 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class.hpp"

string	Contact::getFstName()
{
	return (fst_name);
}

string	Contact::getLstName()
{
	return (lst_name);
}

string	Contact::getNickname()
{
	return (nickname);
}
