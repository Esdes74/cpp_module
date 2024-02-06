/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:57:27 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 11:59:22 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string f_name, std::string l_name, std::string \
		n_name, std::string nb, std::string sec)
{
	fst_name.assign(f_name);
	lst_name.assign(l_name);
	nickname.assign(n_name);
	number.assign(nb);
	secret.assign(sec);
}

void	Contact::afficher()
{
	std::cout << "   Prénom    : " << fst_name << std::endl;
	std::cout << "     Nom     : " << lst_name << std::endl;
	std::cout << "   Surnom    : " << nickname << std::endl;
	std::cout << "Numéros tel. : " << number << std::endl;
	std::cout << "   secret    : " << secret << std::endl;
}
