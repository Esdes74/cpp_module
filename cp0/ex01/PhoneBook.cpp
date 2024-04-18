/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:56:52 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/18 16:18:27 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	current_contact = 0;
	ind_max = 1;
	tab = new Contact[SIZE];
}

// Getters
const int	&PhoneBook::getIndMax() const
{
	return (this->ind_max);
}

/*##############################################################################
 * Bloc de fonction responsable de l'affichage de l'index */

static void	print_info(std::string inf);

void	PhoneBook::afficher()
{
	int	i(0);

	std::cout << "|  index   |  prenom  |   nom    |  surnom  |" << std::endl;
	while (i < 8)
	{
		if (i < ind_max - 1)
		{
			std::cout << "|" << std::setw(10) << i + 1 << "|";
			print_info(tab[i].getFstName());
			print_info(tab[i].getLstName());
			print_info(tab[i].getNickname());
			std::cout << std::endl;
		}
		i++;
	}
}

static void	print_info(std::string inf)
{
	std::string	tronque;

	tronque = inf.substr(0, 9);
	if (tronque != inf)
		std::cout << std::setw(9);
	else
		std::cout << std::setw(10);
	std::cout << tronque;
	if (tronque != inf)
		std::cout << ".";
	std::cout << "|";
}

/* Fin du bloc de fonction responsable de l'affichage de l'index 
 ############################################################################ */

static std::string	demand_string(std::string str);

void	PhoneBook::search(int ind)
{
	tab[ind - 1].afficher();
}

void	PhoneBook::add()
{
	std::string	res;

	if (current_contact == 8)
		current_contact = 0;
	res = demand_string("Prénom : ");
	tab[current_contact].setFstName(res);
	res = demand_string("Nom : ");
	tab[current_contact].setLstName(res);
	res = demand_string("Surnom : ");
	tab[current_contact].setNickname(res);
	res = demand_string("Numéro de téléphone : ");
	tab[current_contact].setPhoneNumber(res);
	res = demand_string("Son plus lourd secret : ");
	tab[current_contact].setSecret(res);
	current_contact++;
	if (ind_max < 9)
		ind_max++;
}

static std::string	demand_string(std::string str)
{
	std::string	res;
	char		c;

	std::cout << str;
	std::getline(std::cin, res);
	if (std::cin.eof())
		exit(1);
	while (res == "")
	{
		c = std::tolower(str[0]);
		std::cout << "Veuillez entrer le " << c << &str[1];
		std::getline(std::cin, res);
		if (std::cin.eof())
			exit(1);
	}
	return (res);
}

PhoneBook::~PhoneBook()
{
	delete[] tab;
}
