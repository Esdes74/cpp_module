/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:19:50 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/21 18:58:50 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <map>
# include <cstring>
# include <cstdlib>
using namespace std;

enum	harl_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl
{
	private:
		void							debug();
		void							info();
		void							warning();
		void							error();
		enum harl_level					level;
		map<string, void(Harl::*)()>	logger;

	public:
		// Constructeur
		Harl(const char *level);

		// Fonctions membres
		void	complain(string level);
};

#endif
