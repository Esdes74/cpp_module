/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:22:46 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/28 15:55:02 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
Claptrap::Claptrap()
{
	cout << "Constructeur Claptrap par defaut appelé\n";
	nom = "";
	pv = 10;
	pe = 10;
	hit = 0;
}

Claptrap::Claptrap(const string &name)
{
	cout << nom << ": Constructeur Claptrap par nom appelé\n";
	this->nom = name;
	pv = 10;
	pe = 10;
	hit = 0;
}

Claptrap::Claptrap(const Claptrap &trap)
{
	cout << this->nom << ": Constructeur Claptrap par copie appelé\n";
	*this = trap;
}

// Surcharge d'opérateur
Claptrap	&Claptrap::operator=(const Claptrap &trap)
{
	cout << nom << ": Surcharge d'opérateur d'affectation Claptrap appelé\n";
	if (this != &trap)
	{
		*this = trap;
	}
	return (*this);
}

// Setters
void	Claptrap::setNom(const string &name)
{
	if (nom == "")
		cout << nom << "Setter nom Claptrap appelé\n";
	else
		cout << nom << ": Setter nom Claptrap appelé\n";
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
string	&Claptrap::getNom()
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
void	Claptrap::attack(const string &target)
{
	if (pe > 0)
	{
		cout << "Le Claptrap ";
		cout << nom << " attaque " << target << " et lui fait " << hit;
		cout << " dégats\n";
		pe--;
	}
	else
		cout << "Le Claptrap " <<  nom << " n'a pas assez d'énergie pour attaquer\n";
}

void	Claptrap::takeDamage(unsigned int amount)
{
	cout << "Le Claptrap ";
	cout << nom << " prends " << amount << " point de dommages il passe de ";
	cout << pv << "pv a " << (int) (pv - amount) << "pv\n";
	pv -= amount;
}

void	Claptrap::beRepaired(unsigned int amount)
{
	if (pe > 0)
	{
		cout << "Le Claptrap ";
		cout << nom;
		cout << " utilise un point d'énergie (passe de " << pe << "pe a " << pe - 1;
		cout << "pe) pour passer de " << pv << "pv a " << (int) (pv + amount);
		cout << "pv\n";
		pe--;
		pv += amount;
	}
	else
	{
		cout << "Le Claptrap ";
		cout << nom << " n'a pas suffisemment de point d'énergie pour se réparrer\n";
	}
}

// Destructor
Claptrap::~Claptrap()
{
	if (pv <= 0)
	{
		cout << "Le Claptrap " << nom << " n'a plus de pv, il meurt\n";
	}
	else
		cout << "Le Claptrap " << nom << " appel son destructeur" << endl;
}
