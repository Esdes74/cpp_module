/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:57:27 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/17 10:56:06 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class.hpp"

Contact::Contact(string f_name, string l_name, string \
		n_name, string nb, string sec)
{
	fst_name.assign(f_name);
	lst_name.assign(l_name);
	nickname.assign(n_name);
	number.assign(nb);
	secret.assign(sec);
}

void	Contact::afficher()
{
	cout << " first name  : " << fst_name << endl;
	cout << "  last name  : " << lst_name << endl;
	cout << "  nickname   : " << nickname << endl;
	cout << "phone number : " << number << endl;
	cout << "   secret    : " << secret << endl;
}
