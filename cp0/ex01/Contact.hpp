/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:07:00 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 11:57:30 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
# define CLASS_HPP

# include <iostream>
# include <sstream>

# define SIZE 8

class	Contact{
	private:
		std::string	fst_name;
		std::string	lst_name;
		std::string	nickname;
		std::string	number;
		std::string	secret;
	public:
		// Constructeur
		Contact(std::string fst_name = "", std::string lst_name = "", std::string \
				nickname = "", std::string nbr = "", std::string secret = "");
		// Setters
		void	setFstName(std::string name);
		void	setLstName(std::string name);
		void	setNickname(std::string name);
		void	setPhoneNumber(std::string nb);
		void	setSecret(std::string sec);
		// Getters
		std::string	getFstName();
		std::string	getLstName();
		std::string	getNickname();
		// Fonctions membres
		void	afficher();
};
#endif
