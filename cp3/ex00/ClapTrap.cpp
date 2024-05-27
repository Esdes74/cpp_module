/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:22:46 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/21 13:16:58 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called\n";
	nom = "";
	pv = 10;
	pe = 10;
	hit = 0;
}

ClapTrap::ClapTrap(const std::string &name)
{
	if (nom == "")
		std::cout << name << ": Name constructor called\n";
	else
		std::cout << nom << ": Name constructor called\n";
	this->nom = name;
	pv = 10;
	pe = 10;
	hit = 0;
}

ClapTrap::ClapTrap(const ClapTrap &trap)
{
	std::cout << this->nom << ": Copy constructor called\n";
	*this = trap;
}

// Surcharge d'opérateur
ClapTrap	&ClapTrap::operator=(const ClapTrap &trap)
{
	std::cout << nom << ": Copy assignment operator called\n";
	if (this != &trap)
	{
		this->nom = trap.nom;
		this->pv = trap.pv;
		this->pe = trap.pe;
		this->hit = trap.hit;
	}
	return (*this);
}

// Setters
void	ClapTrap::setNom(const std::string &name)
{
	if (nom == "")
		std::cout << name << ": Setter name called\n";
	else
		std::cout << nom << ": Setter name called\n";
	this->nom = name;
}

void	ClapTrap::setPV(const int &pv)
{
	std::cout << nom << ": Setter hp called\n";
	this->pv = pv;
}

void	ClapTrap::setPE(const unsigned int &pe)
{
	std::cout << nom << ": Setter pe called\n";
	this->pe = pe;
}

void	ClapTrap::setHIT(const unsigned int &hit)
{
	std::cout << nom << ": Setter hit called\n";
	this->hit = hit;
}

// Getters
const std::string	&ClapTrap::Nom() const
{
	std::cout << nom << ": Getter constant name called\n";
	return (this->nom);
}

const int	&ClapTrap::PV() const
{
	std::cout << nom << ": Getter constant hp called\n";
	return (this->pv);
}

const unsigned int	&ClapTrap::PE() const
{
	std::cout << nom << ": Getter constant pe called\n";
	return (this->pe);
}

const unsigned int	&ClapTrap::HIT() const
{
	std::cout << nom << ": Getter constant hit called\n";
	return (this->hit);
}

std::string	&ClapTrap::getNom()
{
	std::cout << nom << ": Getter name called\n";
	return (this->nom);
}

int	&ClapTrap::getPV()
{
	std::cout << nom << ": Getter hp called\n";
	return (this->pv);
}

unsigned int	&ClapTrap::getPE()
{
	std::cout << nom << ": Getter pe called\n";
	return (this->pe);
}

unsigned int	&ClapTrap::getHIT()
{
	std::cout << nom << ": Getter hit called\n";
	return (this->hit);
}

// Fonctions membres
void	ClapTrap::attack(const std::string &target)
{
	if (pe > 0)
	{
		std::cout << nom << " attack " << target << " and do him " << hit;
		std::cout << " damage\n";
		pe--;
	}
	else
		std::cout << nom << " don't have enought energy\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << nom << " take " << amount << " damage point he goes from ";
	std::cout << pv << "hp to " <<  pv - (int) amount << "hp\n";
	pv -= amount;
	if (pv <= 0)
		std::cout << nom << " no longer has hp, he's dies\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (pe > 0)
	{
		std::cout << nom;
		std::cout << " use an energy point (goes from " << pe << "pe to " << pe - 1;
		std::cout << "pe) to goes from " << pv << "hp to " << pv + (int) amount << "hp\n";
		pe--;
		pv += amount;
	}
	else
	{
		std::cout << nom << " don't have enought energy point to repaire himself\n";
	}
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << nom << ": Destructor called" << std::endl;
}
