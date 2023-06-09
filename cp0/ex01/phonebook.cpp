/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:56:52 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/18 09:23:46 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class.hpp"

PhoneBook::PhoneBook()
{
	current_contact = 0;
	tab = new Contact[SIZE];
}

/*##############################################################################
 * Bloc de fonction responsable de l'affichage de l'index */

static void	print_info(string inf)
{
	int	i(0);

	if (inf.length() > 10)
	{
		while (i < 9)
			cout << inf[i++];
		cout << ".";
	}
	else
	{
		while ((i++) < (int) (10 - inf.length()))
			cout << " ";
		cout << inf;
	}
	cout << "|";
}

void	PhoneBook::afficher()
{
	int	i(0);

	cout << "|  index   |  prenom  |   nom    |  surnom  |" << endl;
	while (i < 8)
	{
		cout << "|         " << i + 1 << "|";
		if (tab[i].getFstName() == "")
			cout << "          |          |          |";
		else
		{
			print_info(tab[i].getFstName());
			print_info(tab[i].getLstName());
			print_info(tab[i].getNickname());
		}
		cout << endl;
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
	string	res;

	if (current_contact == 8)
		current_contact = 0;
	cout << "Prénom : ";
	getline(cin, res);
	tab[current_contact].setFstName(res);
	cout << "Nom : ";
	getline(cin, res);
	tab[current_contact].setLstName(res);
	cout << "Surnom : ";
	getline(cin, res);
	tab[current_contact].setNickname(res);
	cout << "Numéro de téléphone : ";
	getline(cin, res);
	tab[current_contact].setPhoneNumber(res);
	cout << "Son plus lourd secret : ";
	getline(cin, res);
	tab[current_contact].setSecret(res);
	current_contact++;
}

PhoneBook::~PhoneBook()
{
	delete[] tab;
}
