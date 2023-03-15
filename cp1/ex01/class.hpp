/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:07:00 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/15 16:36:51 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
# define CLASS_HPP

# include <iostream>
# include <string>

using namespace std;

class	Contact{
	private:
		string	fst_name;
		string	lst_name;
		string	nickname;
		string	number;
		string	secret;
	public:
		Contact(string fst_name, string lst_name, string nickname, string nbr, \
				string secret);
		void	afficher();
};

class	PhoneBook{
	private:
		Contact	tab[8];
		int		current_contact;
	public:
		PhoneBook(class Contact[8], int current_contact);
		void	afficher();
		void	search(int ind);
};
#endif
