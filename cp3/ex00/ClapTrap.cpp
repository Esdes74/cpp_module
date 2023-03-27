/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:22:46 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/27 18:58:28 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
Claptrap::Claptrap()
{
	cout << "Constructeur par defaut appelé\n";
	nom = "";
	pv = 10;
	pe = 10;
	hit = 0;
}

Claptrap::Claptrap(const string &name)
{
	cout << nom << ": Constructeur par nom appelé\n";
	this->nom = name;
	pv = 10;
	pe = 10;
	hit = 0;
}

Claptrap::Claptrap(const Claptrap &trap)
{
	cout << this->nom << ": Constructeur par copie appelé\n";
	*this = trap;
}

// Surcharge d'opérateur
Claptrap	&Claptrap::operator=(const Claptrap &trap)
{
	cout << nom << ": Surcharge d'opérateur d'affectation appelé\n";
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
		cout << nom << "Setter nom appelé\n";
	else
		cout << nom << ": Setter nom appelé\n";
	this->nom = name;
}

void	Claptrap::setPV(const int &pv)
{
	cout << nom << ": Setter pv appelé\n";
	this->pv = pv;
}

void	Claptrap::setPE(const unsigned int &pe)
{
	cout << nom << ": Setter pe appelé\n";
	this->pe = pe;
}

void	Claptrap::setHIT(const unsigned int &hit)
{
	cout << nom << ": Setter hit appelé\n";
	this->hit = hit;
}

// Getters
string	&Claptrap::getNom()
{
	cout << nom << ": Getter nom appelé\n";
	return (this->nom);
}

int	&Claptrap::getPV()
{
	cout << nom << ": Getter pv appelé\n";
	return (this->pv);
}

unsigned int	&Claptrap::getPE()
{
	cout << nom << ": Getter pe appelé\n";
	return (this->pe);
}

unsigned int	&Claptrap::getHIT()
{
	cout << nom << ": Getter hit appelé\n";
	return (this->hit);
}

// Fonctions membres
void	Claptrap::attack(const string &target)
{
	if (pe > 0)
	{
		cout << nom << " attaque " << target << " et lui fait " << hit;
		cout << " dégats\n";
		pe--;
	}
	else
		cout << nom << " n'a pas assez d'énergie pour attaquer\n";
}

void	Claptrap::takeDamage(unsigned int amount)
{
	cout << nom << " prends " << amount << " point de dommages il passe de ";
	cout << pv << "pv a " << (int) (pv - amount) << "pv\n";
	pv -= amount;
	if (pv <= 0)
		delete this;
}

void	Claptrap::beRepaired(unsigned int amount)
{
	if (pe > 0)
	{
		cout << nom;
		cout << " utilise un point d'énergie (passe de " << pe << "pe a " << pe - 1;
		cout << "pe) pour passer de " << pv << "pv a " << pv + amount << "pv\n";
		pe--;
		pv += amount;
	}
	else
	{
		cout << nom << " n'a pas suffisemment de point d'énergie pour se réparrer\n";
	}
}

// Destructor
Claptrap::~Claptrap()
{
	if (pv <= 0)
	{
		cout << nom << " n'a plus de pv, il meurt\n";
	}
	else
		cout << nom << ": Destructeur appelé pour " << endl;
}
