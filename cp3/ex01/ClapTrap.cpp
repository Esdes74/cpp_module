/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:22:46 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/05 12:59:38 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap()
{
	std::cout << "Default Claptrap constructor called\n";
	nom = "";
	pv = 10;
	pe = 10;
	hit = 0;
}

ClapTrap::ClapTrap(const std::string &name)
{
	if (nom == "")
		std::cout << name << ": Name Claptrap constructor called\n";
	else
		std::cout << nom << ": Name Claptrap constructor called\n";
	this->nom = name;
	pv = 10;
	pe = 10;
	hit = 0;
}

ClapTrap::ClapTrap(const ClapTrap &trap)
{
	std::cout << this->nom << ": Copy Claptrap constructor called\n";
	*this = trap;
}

// Surcharge d'opérateur
ClapTrap	&ClapTrap::operator=(const ClapTrap &trap)
{
	std::cout << nom << ": Copy Claptrap assignment operator called\n";
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
		std::cout << nom << "Setter name ClapTrap called\n";
	else
		std::cout << nom << ": Setter name ClapTrap called\n";
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
		std::cout << "ClapTrap ";
		std::cout << nom << " attack " << target << " and do him " << hit;
		std::cout << " damage\n";
		pe--;
	}
	else
		std::cout << "ClapTrap " <<  nom << " don't have enought energy to attack\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap ";
	std::cout << nom << " take " << amount << " damage point he goes from ";
	std::cout << pv << "hp to " << pv - (int) amount << "hp\n";
	pv -= amount;
	if (pv <= 0)
		std::cout << nom << " no longer has hp, he's dies\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (pe > 0)
	{
		std::cout << "ClapTrap ";
		std::cout << nom;
		std::cout << " use an energy point (goes from " << pe << "pe to " << pe - 1;
		std::cout << "pe) to goes from " << pv << "hp to " << pv + (int) amount << "hp\n";
		pe--;
		pv += amount;
	}
	else
	{
		std::cout << "ClapTrap ";
		std::cout << nom << " don't have enought energy point to repaire himself\n";
	}
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << nom << " call his destructor" << std::endl;
}
