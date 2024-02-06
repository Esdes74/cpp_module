/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:25:17 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 11:53:49 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFstName(string name)
{
	fst_name.assign(name);
}

void	Contact::setLstName(string name)
{
	lst_name.assign(name);
}

void	Contact::setNickname(string name)
{
	nickname.assign(name);
}

void	Contact::setPhoneNumber(string name)
{
	number.assign(name);
}

void	Contact::setSecret(string name)
{
	secret.assign(name);
}
