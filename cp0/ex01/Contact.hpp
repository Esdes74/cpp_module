/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:07:00 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 11:52:43 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
# define CLASS_HPP

# include <iostream>
# include <sstream>

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
		// Constructeur
		Contact(string fst_name = "", string lst_name = "", string \
				nickname = "", string nbr = "", string secret = "");
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
#endif
