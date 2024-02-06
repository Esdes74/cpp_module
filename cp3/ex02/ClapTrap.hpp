/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:05:01 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 13:32:30 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class Claptrap
{
	protected:
		std::string			nom;
		int				pv;
		unsigned int	pe;
		unsigned int	hit;

	public:
		// Constructors
		Claptrap();
		Claptrap(const std::string &name);
		Claptrap(const Claptrap &trap);

		// Surcharge d'opérateur
		Claptrap		&operator=(const Claptrap &trap);

		// Setters
		void			setNom(const std::string &name);
		void			setPV(const int &pv);
		void			setPE(const unsigned int &pe);
		void			setHIT(const unsigned int &hit);

		// Getters
		std::string			&getNom();
		int				&getPV();
		unsigned int	&getPE();
		unsigned int	&getHIT();

		// Fonctions membres
		virtual void	attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		// Destructor
		virtual	~Claptrap();
};

#endif
