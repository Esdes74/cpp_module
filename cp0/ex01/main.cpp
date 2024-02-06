/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:08:52 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/06 11:01:09 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class.hpp"

int	main()
{
	PhoneBook	book;
	string		res;
	int			index;

	cout << "Vous avez le chois entre 3 actions pendant l'éxécution du \
programme \nADD : Vous permet d'ajouter un membre a votre PhoneBook\nSEARCH : \
Qui imprime l'index de votre PhoneBook, vous pouvez ainsi demander un contact\n\
EXIT : Sort du programme\nQue voulez vous faire ?\n";
	while (true)
	{
		getline(cin, res);
		if (std::cin.eof())
			break ;
		while (res != "ADD" && res != "SEARCH" && res != "EXIT")
		{
			cout << "Votre commande n'est pas correcte veuillez retaper s'il vous \
plait\n";
			getline(cin, res);
		}
		if (res == "EXIT")
			return (0);
		else if (res == "SEARCH")
		{
			book.afficher();
			cout << "Quelle contact voulez vous voir ? (entrez le numéro de la \
ligne inscrit dans la colonne indexe)\n";
			getline(cin, res);
			istringstream iss(res);
			iss >> index;
			while (index < 0 || index > 8)
			{
				cout << "Le numéros de ligne que vous avez donné n'est pas bon\
pouvez vous en redonner un ?\n";
				getline(cin, res);
				istringstream iss(res);
				iss >> index;
			}
			book.search(index);
		}
		else
			book.add();
		cout << "Que voulez vous faire ?\n";
	}
}
