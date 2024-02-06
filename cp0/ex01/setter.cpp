/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:25:17 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 12:00:49 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFstName(std::string name)
{
	fst_name.assign(name);
}

void	Contact::setLstName(std::string name)
{
	lst_name.assign(name);
}

void	Contact::setNickname(std::string name)
{
	nickname.assign(name);
}

void	Contact::setPhoneNumber(std::string name)
{
	number.assign(name);
}

void	Contact::setSecret(std::string name)
{
	secret.assign(name);
}
