/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:07:00 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/16 18:34:44 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
# define CLASS_HPP

# include <iostream>
# include <string>

using namespace std;

# define SIZE 8

class	Contact{
	private:
		string	fst_name;
		string	lst_name;
		string	nickname;
		string	number;
		string	secret;
	public:
		// Constructeurs
		Contact();
		Contact(string fst_name, string lst_name, string \
				nickname, string nbr, string secret);
		// Setters
		void	setFstName(string name);
		void	setLstName(string name);
		void	setNickname(string name);
		void	setPhoneNumber(string nb);
		void	setSecret(string sec);
		// Getters
		string	getFstName();
		string	getLstName();
		string	getNickname();
		// Fonctions membres
		void	afficher();
};

class	PhoneBook{
	private:
		Contact	*tab;
		int		current_contact;
	public:
		// Constructeurs
		PhoneBook();
		// Fonctions membres
		void	afficher();
		void	search(int ind);
		void	add();
		// Destructeur
		~PhoneBook();
};
#endif
