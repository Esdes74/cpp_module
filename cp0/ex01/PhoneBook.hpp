/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:35 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/18 16:00:30 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>
# include <iomanip>

class	PhoneBook{
	private:
		Contact		*tab;
		int			current_contact;
		int			ind_max;

	public:
		// Constructeurs
		PhoneBook();

		// Getters
		const int	&getIndMax() const;

		// Fonctions membres
		void		afficher();
		void		search(int ind);
		void		add();

		// Destructeur
		~PhoneBook();
};
#endif
