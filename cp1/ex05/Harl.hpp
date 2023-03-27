/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:19:50 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/21 14:24:55 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <map>
using namespace std;

class Harl
{
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();
		map<string, void(Harl::*)()> logger;

	public:
		// Constructeur
		Harl();

		// Fonctions membres
		void	complain(string level);
};

#endif
