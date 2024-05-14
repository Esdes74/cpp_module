/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:08:52 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/14 15:00:36 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	book;
	std::string	res;
	int			index;

	std::cout << "You can choose between 3 actions\n\
ADD : add a member to your phonebook\n\
SEARCH : print index of your phonebook, you can choose a contact and print details\n\
EXIT: exit the program\n\
What do you want to do ?\n";
	while (1)
	{
		std::getline(std::cin, res);
		if (std::cin.eof())
			exit(1);
		while (res != "ADD" && res != "SEARCH" && res != "EXIT")
		{
			std::cout << "Wrong command, Please try again : ADD, SEARCH, EXIT\n";
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
				std::cout << "There's nobody in your phonebook, please add some\n";
			}
			else
			{
				book.afficher();
				std::cout << "Wich contact do you want to see ? (give number on left column)\n";
				std::getline(std::cin, res);
				if (std::cin.eof())
					exit(1);
				std::istringstream iss(res);
				iss >> index;
				while (index < 1 || index > book.getIndMax() - 1)
				{
					std::cout << "Wrong number try again ?\n";
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
		std::cout << "What do you want to do ?\n";
	}
}
