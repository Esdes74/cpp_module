/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:35 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 14:19:22 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

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
