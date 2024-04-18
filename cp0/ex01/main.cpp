/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:08:52 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/18 16:12:50 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	book;
	std::string	res;
	int			index;

	std::cout << "Vous avez le chois entre 3 actions pendant l'éxécution du \
programme \nADD : Vous permet d'ajouter un membre a votre PhoneBook\nSEARCH : \
Qui imprime l'index de votre PhoneBook, vous pouvez ainsi demander un contact\n\
EXIT : Sort du programme\nQue voulez vous faire ?\n";
	while (1)
	{
		std::getline(std::cin, res);
		if (std::cin.eof())
			exit(1);
		while (res != "ADD" && res != "SEARCH" && res != "EXIT")
		{
			std::cout << "Votre commande n'est pas correcte veuillez retaper s'il vous \
plait\n";
			std::getline(std::cin, res);
			if (std::cin.eof())
				exit(1);
		}
		if (res == "EXIT")
			return (0);
		else if (res == "SEARCH")
		{
			if (book.getIndMax() == 1)
			{
				std::cout << "Il n'y a pas encore de contacts dans l'annuaire, \
veuillez en ajouter\n";
			}
			else
			{
				book.afficher();
				std::cout << "Quelle contact voulez vous voir ? (entrez le \
numéro de la ligne inscrit dans la colonne indexe)\n";
				std::getline(std::cin, res);
				if (std::cin.eof())
					exit(1);
				std::istringstream iss(res);
				iss >> index;
				while (index < 1 || index > book.getIndMax() - 1)
				{
					std::cout << "Le numéros de ligne que vous avez donné n'est \
pas bon pouvez vous en redonner un ?\n";
					std::getline(std::cin, res);
					if (std::cin.eof())
						exit(1);
					std::istringstream iss(res);
					iss >> index;
				}
				book.search(index);
				index = 0;
			}
		}
		else
			book.add();
		std::cout << "Que voulez vous faire ?\n";
	}
}
