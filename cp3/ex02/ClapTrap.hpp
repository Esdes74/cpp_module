/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:05:01 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/28 15:49:32 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
using namespace std;

class Claptrap
{
	protected:
		string			nom;
		int				pv;
		unsigned int	pe;
		unsigned int	hit;

	public:
		// Constructors
		Claptrap();
		Claptrap(const string &name);
		Claptrap(const Claptrap &trap);

		// Surcharge d'opérateur
		Claptrap		&operator=(const Claptrap &trap);

		// Setters
		void			setNom(const string &name);
		void			setPV(const int &pv);
		void			setPE(const unsigned int &pe);
		void			setHIT(const unsigned int &hit);

		// Getters
		string			&getNom();
		int				&getPV();
		unsigned int	&getPE();
		unsigned int	&getHIT();

		// Fonctions membres
		virtual void	attack(const string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		// Destructor
		virtual	~Claptrap();
};

#endif
