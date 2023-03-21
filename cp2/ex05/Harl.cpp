/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:22:30 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/21 18:48:29 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	this->logger["DEBUG"] = &Harl::debug;
	this->logger["INFO"] = &Harl::info;
	this->logger["WARNING"] = &Harl::warning;
	this->logger["ERROR"] = &Harl::error;
}

void	Harl::debug()
{
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-\
specialketchup burger. I really do !\n";
}

void	Harl::info()
{
	cout << "I cannot believe adding extra bacon costs more money. You didn’t \
put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n";
}

void	Harl::warning()
{
	cout << "I think I deserve to have some extra bacon for free. I’ve been \
coming for years whereas you started working here since last month.\n";
}

void	Harl::error()
{
	cout << "This is unacceptable ! I want to speak to the manager now.\n";
}

void	Harl::complain(string level)
{
	map<string, void(Harl::*)()>::iterator it = logger.find(level);

	if (it != logger.end())
		(this->*(it->second))();
}
