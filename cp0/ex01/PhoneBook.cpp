/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:56:52 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 12:00:18 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	current_contact = 0;
	tab = new Contact[SIZE];
}

/*##############################################################################
 * Bloc de fonction responsable de l'affichage de l'index */

static void	print_info(std::string inf)
{
	int	i(0);

	if (inf.length() > 10)
	{
		while (i < 9)
			std::cout << inf[i++];
		std::cout << ".";
	}
	else
	{
		while ((i++) < (int) (10 - inf.length()))
			std::cout << " ";
		std::cout << inf;
	}
	std::cout << "|";
}

void	PhoneBook::afficher()
{
	int	i(0);

	std::cout << "|  index   |  prenom  |   nom    |  surnom  |" << std::endl;
	while (i < 8)
	{
		std::cout << "|         " << i + 1 << "|";
		if (tab[i].getFstName() == "")
			std::cout << "          |          |          |";
		else
		{
			print_info(tab[i].getFstName());
			print_info(tab[i].getLstName());
			print_info(tab[i].getNickname());
		}
		std::cout << std::endl;
		i++;
	}
}

/* Fin du bloc de fonction responsable de l'affichage de l'index 
 ############################################################################ */

void	PhoneBook::search(int ind)
{
	tab[ind - 1].afficher();
}

void	PhoneBook::add()
{
	std::string	res;

	if (current_contact == 8)
		current_contact = 0;
	std::cout << "Prénom : ";
	std::getline(std::cin, res);
	tab[current_contact].setFstName(res);
	std::cout << "Nom : ";
	std::getline(std::cin, res);
	tab[current_contact].setLstName(res);
	std::cout << "Surnom : ";
	std::getline(std::cin, res);
	tab[current_contact].setNickname(res);
	std::cout << "Numéro de téléphone : ";
	std::getline(std::cin, res);
	tab[current_contact].setPhoneNumber(res);
	std::cout << "Son plus lourd secret : ";
	std::getline(std::cin, res);
	tab[current_contact].setSecret(res);
	current_contact++;
}

PhoneBook::~PhoneBook()
{
	delete[] tab;
}
