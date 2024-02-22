/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:19:50 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/22 15:09:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	private:
		void		debug();
		void		info();
		void		warning();
		void		error();
		void		(Harl::*funcs[4])();
		std::string	mod[4];

	public:
		// Constructeur
		Harl();

		// Fonctions membres
		void	complain(std::string level);
};

#endif
