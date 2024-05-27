/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:57:27 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/14 15:02:20 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor
Contact::Contact(std::string f_name, std::string l_name, std::string \
		n_name, std::string nb, std::string sec)
{
	fst_name.assign(f_name);
	lst_name.assign(l_name);
	nickname.assign(n_name);
	number.assign(nb);
	secret.assign(sec);
}

// Setters
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

// Getters
std::string	Contact::getFstName() const
{
	return (fst_name);
}

std::string	Contact::getLstName() const
{
	return (lst_name);
}

std::string	Contact::getNickname() const
{
	return (nickname);
}

// Fonctions membres
void	Contact::afficher()
{
	std::cout << "    Name     : " << fst_name << std::endl;
	std::cout << "  Last Name  : " << lst_name << std::endl;
	std::cout << "  Nickname   : " << nickname << std::endl;
	std::cout << "Telephone nb.: " << number << std::endl;
	std::cout << "   Secret    : " << secret << std::endl;
}
