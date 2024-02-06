/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:22:46 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 13:29:12 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
Claptrap::Claptrap()
{
	std::cout << "Constructeur par defaut appelé\n";
	nom = "";
	pv = 10;
	pe = 10;
	hit = 0;
}

Claptrap::Claptrap(const std::string &name)
{
	std::cout << nom << ": Constructeur par nom appelé\n";
	this->nom = name;
	pv = 10;
	pe = 10;
	hit = 0;
}

Claptrap::Claptrap(const Claptrap &trap)
{
	std::cout << this->nom << ": Constructeur par copie appelé\n";
	*this = trap;
}

// Surcharge d'opérateur
Claptrap	&Claptrap::operator=(const Claptrap &trap)
{
	std::cout << nom << ": Surcharge d'opérateur d'affectation appelé\n";
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
		std::cout << nom << "Setter nom appelé\n";
	else
		std::cout << nom << ": Setter nom appelé\n";
	this->nom = name;
}

void	Claptrap::setPV(const int &pv)
{
	std::cout << nom << ": Setter pv appelé\n";
	this->pv = pv;
}

void	Claptrap::setPE(const unsigned int &pe)
{
	std::cout << nom << ": Setter pe appelé\n";
	this->pe = pe;
}

void	Claptrap::setHIT(const unsigned int &hit)
{
	std::cout << nom << ": Setter hit appelé\n";
	this->hit = hit;
}

// Getters
std::string	&Claptrap::getNom()
{
	std::cout << nom << ": Getter nom appelé\n";
	return (this->nom);
}

int	&Claptrap::getPV()
{
	std::cout << nom << ": Getter pv appelé\n";
	return (this->pv);
}

unsigned int	&Claptrap::getPE()
{
	std::cout << nom << ": Getter pe appelé\n";
	return (this->pe);
}

unsigned int	&Claptrap::getHIT()
{
	std::cout << nom << ": Getter hit appelé\n";
	return (this->hit);
}

// Fonctions membres
void	Claptrap::attack(const std::string &target)
{
	if (pe > 0)
	{
		std::cout << nom << " attaque " << target << " et lui fait " << hit;
		std::cout << " dégats\n";
		pe--;
	}
	else
		std::cout << nom << " n'a pas assez d'énergie pour attaquer\n";
}

void	Claptrap::takeDamage(unsigned int amount)
{
	std::cout << nom << " prends " << amount << " point de dommages il passe de ";
	std::cout << pv << "pv a " << (int) (pv - amount) << "pv\n";
	pv -= amount;
	if (pv <= 0)
		delete this;
}

void	Claptrap::beRepaired(unsigned int amount)
{
	if (pe > 0)
	{
		std::cout << nom;
		std::cout << " utilise un point d'énergie (passe de " << pe << "pe a " << pe - 1;
		std::cout << "pe) pour passer de " << pv << "pv a " << pv + amount << "pv\n";
		pe--;
		pv += amount;
	}
	else
	{
		std::cout << nom << " n'a pas suffisemment de point d'énergie pour se réparrer\n";
	}
}

// Destructor
Claptrap::~Claptrap()
{
	if (pv <= 0)
	{
		std::cout << nom << " n'a plus de pv, il meurt\n";
	}
	else
		std::cout << nom << ": Destructeur appelé pour " << std::endl;
}
