/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:22:46 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 13:31:08 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
Claptrap::Claptrap()
{
	std::cout << "Constructeur Claptrap par defaut appelé\n";
	nom = "";
	pv = 10;
	pe = 10;
	hit = 0;
}

Claptrap::Claptrap(const std::string &name)
{
	std::cout << nom << ": Constructeur Claptrap par nom appelé\n";
	this->nom = name;
	pv = 10;
	pe = 10;
	hit = 0;
}

Claptrap::Claptrap(const Claptrap &trap)
{
	std::cout << this->nom << ": Constructeur Claptrap par copie appelé\n";
	*this = trap;
}

// Surcharge d'opérateur
Claptrap	&Claptrap::operator=(const Claptrap &trap)
{
	std::cout << nom << ": Surcharge d'opérateur d'affectation Claptrap appelé\n";
	if (this != &trap)
	{
		*this = trap;
	}
	return (*this);
}

// Setters
void	Claptrap::setNom(const std::string &name)
{
	if (nom == "")
		std::cout << nom << "Setter nom Claptrap appelé\n";
	else
		std::cout << nom << ": Setter nom Claptrap appelé\n";
	this->nom = name;
}

void	Claptrap::setPV(const int &pv)
{
	this->pv = pv;
}

void	Claptrap::setPE(const unsigned int &pe)
{
	this->pe = pe;
}

void	Claptrap::setHIT(const unsigned int &hit)
{
	this->hit = hit;
}

// Getters
std::string	&Claptrap::getNom()
{
	return (this->nom);
}

int	&Claptrap::getPV()
{
	return (this->pv);
}

unsigned int	&Claptrap::getPE()
{
	return (this->pe);
}

unsigned int	&Claptrap::getHIT()
{
	return (this->hit);
}

// Fonctions membres
void	Claptrap::attack(const std::string &target)
{
	if (pe > 0)
	{
		std::cout << "Le Claptrap ";
		std::cout << nom << " attaque " << target << " et lui fait " << hit;
		std::cout << " dégats\n";
		pe--;
	}
	else
		std::cout << "Le Claptrap " <<  nom << " n'a pas assez d'énergie pour attaquer\n";
}

void	Claptrap::takeDamage(unsigned int amount)
{
	std::cout << "Le Claptrap ";
	std::cout << nom << " prends " << amount << " point de dommages il passe de ";
	std::cout << pv << "pv a " << (int) (pv - amount) << "pv\n";
	pv -= amount;
}

void	Claptrap::beRepaired(unsigned int amount)
{
	if (pe > 0)
	{
		std::cout << "Le Claptrap ";
		std::cout << nom;
		std::cout << " utilise un point d'énergie (passe de " << pe << "pe a " << pe - 1;
		std::cout << "pe) pour passer de " << pv << "pv a " << (int) (pv + amount);
		std::cout << "pv\n";
		pe--;
		pv += amount;
	}
	else
	{
		std::cout << "Le Claptrap ";
		std::cout << nom << " n'a pas suffisemment de point d'énergie pour se réparrer\n";
	}
}

// Destructor
Claptrap::~Claptrap()
{
	if (pv <= 0)
	{
		std::cout << "Le Claptrap " << nom << " n'a plus de pv, il meurt\n";
	}
	else
		std::cout << "Le Claptrap " << nom << " appel son destructeur" << std::endl;
}