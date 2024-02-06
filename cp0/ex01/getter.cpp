/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:24:38 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 11:53:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
