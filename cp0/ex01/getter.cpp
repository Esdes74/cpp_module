/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:24:38 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 12:00:34 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::getFstName()
{
	return (fst_name);
}

std::string	Contact::getLstName()
{
	return (lst_name);
}

std::string	Contact::getNickname()
{
	return (nickname);
}
