/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:22:46 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/26 16:41:55 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap()
{
	std::cout << "Constructeur ClapTrap par defaut appelé\n";
	nom = "";
	pv = 10;
	pe = 10;
	hit = 0;
}

ClapTrap::ClapTrap(const std::string &name)
{
	std::cout << nom << ": Constructeur ClapTrap par nom appelé\n";
	this->nom = name;
	pv = 10;
	pe = 10;
	hit = 0;
}

ClapTrap::ClapTrap(const ClapTrap &trap)
{
	std::cout << this->nom << ": Constructeur ClapTrap par copie appelé\n";
	*this = trap;
}

// Surcharge d'opérateur
ClapTrap	&ClapTrap::operator=(const ClapTrap &trap)
{
	std::cout << nom << ": Surcharge d'opérateur d'affectation ClapTrap appelé\n";
	if (this != &trap)
	{
		*this = trap;
	}
	return (*this);
}

// Setters
void	ClapTrap::setNom(const std::string &name)
{
	if (nom == "")
		std::cout << nom << "Setter nom ClapTrap appelé\n";
	else
		std::cout << nom << ": Setter nom ClapTrap appelé\n";
	this->nom = name;
}

void	ClapTrap::setPV(const int &pv)
{
	this->pv = pv;
}

void	ClapTrap::setPE(const unsigned int &pe)
{
	this->pe = pe;
}

void	ClapTrap::setHIT(const unsigned int &hit)
{
	this->hit = hit;
}

// Getters
std::string	&ClapTrap::getNom()
{
	return (this->nom);
}

int	&ClapTrap::getPV()
{
	return (this->pv);
}

unsigned int	&ClapTrap::getPE()
{
	return (this->pe);
}

unsigned int	&ClapTrap::getHIT()
{
	return (this->hit);
}

// Fonctions membres
void	ClapTrap::attack(const std::string &target)
{
	if (pe > 0)
	{
		std::cout << "Le ClapTrap ";
		std::cout << nom << " attaque " << target << " et lui fait " << hit;
		std::cout << " dégats\n";
		pe--;
	}
	else
		std::cout << "Le ClapTrap " <<  nom << " n'a pas assez d'énergie pour attaquer\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Le ClapTrap ";
	std::cout << nom << " prends " << amount << " point de dommages il passe de ";
	std::cout << pv << "pv a " << (int) (pv - amount) << "pv\n";
	pv -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (pe > 0)
	{
		std::cout << "Le ClapTrap ";
		std::cout << nom;
		std::cout << " utilise un point d'énergie (passe de " << pe << "pe a " << pe - 1;
		std::cout << "pe) pour passer de " << pv << "pv a " << (int) (pv + amount);
		std::cout << "pv\n";
		pe--;
		pv += amount;
	}
	else
	{
		std::cout << "Le ClapTrap ";
		std::cout << nom << " n'a pas suffisemment de point d'énergie pour se réparrer\n";
	}
}

// Destructor
ClapTrap::~ClapTrap()
{
	if (pv <= 0)
	{
		std::cout << "Le ClapTrap " << nom << " n'a plus de pv, il meurt\n";
	}
	else
		std::cout << "Le ClapTrap " << nom << " appel son destructeur" << std::endl;
}
