/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:22:46 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/26 15:32:37 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap()
{
	std::cout << "Constructeur par defaut appelé\n";
	nom = "";
	pv = 10;
	pe = 10;
	hit = 0;
}

ClapTrap::ClapTrap(const std::string &name)
{
	std::cout << nom << ": Constructeur par nom appelé\n";
	this->nom = name;
	pv = 10;
	pe = 10;
	hit = 0;
}

ClapTrap::ClapTrap(const ClapTrap &trap)
{
	std::cout << this->nom << ": Constructeur par copie appelé\n";
	*this = trap;
}

// Surcharge d'opérateur
ClapTrap	&ClapTrap::operator=(const ClapTrap &trap)
{
	std::cout << nom << ": Surcharge d'opérateur d'affectation appelé\n";
	if (this != &trap)
		*this = trap;
	return (*this);
}

// Setters
void	ClapTrap::setNom(const std::string &name)
{
	if (nom == "")
		std::cout << nom << "Setter nom appelé\n";
	else
		std::cout << nom << ": Setter nom appelé\n";
	this->nom = name;
}

void	ClapTrap::setPV(const int &pv)
{
	std::cout << nom << ": Setter pv appelé\n";
	this->pv = pv;
}

void	ClapTrap::setPE(const unsigned int &pe)
{
	std::cout << nom << ": Setter pe appelé\n";
	this->pe = pe;
}

void	ClapTrap::setHIT(const unsigned int &hit)
{
	std::cout << nom << ": Setter hit appelé\n";
	this->hit = hit;
}

// Getters
const std::string	&ClapTrap::Nom() const
{
	std::cout << nom << ": Getter nom constant appelé\n";
	return (this->nom);
}

const int	&ClapTrap::PV() const
{
	std::cout << nom << ": Getter pv constant appelé\n";
	return (this->pv);
}

const unsigned int	&ClapTrap::PE() const
{
	std::cout << nom << ": Getter pe constant appelé\n";
	return (this->pe);
}

const unsigned int	&ClapTrap::HIT() const
{
	std::cout << nom << ": Getter hit constant appelé\n";
	return (this->hit);
}

std::string	&ClapTrap::getNom()
{
	std::cout << nom << ": Getter nom appelé\n";
	return (this->nom);
}

int	&ClapTrap::getPV()
{
	std::cout << nom << ": Getter pv appelé\n";
	return (this->pv);
}

unsigned int	&ClapTrap::getPE()
{
	std::cout << nom << ": Getter pe appelé\n";
	return (this->pe);
}

unsigned int	&ClapTrap::getHIT()
{
	std::cout << nom << ": Getter hit appelé\n";
	return (this->hit);
}

// Fonctions membres
void	ClapTrap::attack(const std::string &target)
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << nom << " prends " << amount << " point de dommages il passe de ";
	std::cout << pv << "pv a " << (int) (pv - amount) << "pv\n";
	pv -= amount;
	if (pv <= 0)
		delete this;
}

void	ClapTrap::beRepaired(unsigned int amount)
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
ClapTrap::~ClapTrap()
{
	if (pv <= 0)
	{
		std::cout << nom << " n'a plus de pv, il meurt\n";
	}
	else
		std::cout << nom << ": Destructeur appelé pour " << std::endl;
}
