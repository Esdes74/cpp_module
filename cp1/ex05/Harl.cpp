/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:22:30 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/22 15:49:51 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <stdio.h>

Harl::Harl()
{
	funcs[0] = &Harl::debug;
	funcs[1] = &Harl::info;
	funcs[2] = &Harl::warning;
	funcs[3] = &Harl::error;
	this->mod[0] = "DEBUG";
	this->mod[1] = "INFO";
	this->mod[2] = "WARNING";
	this->mod[3] = "ERROR";
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-\
specialketchup burger. I really do !\n";
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t \
put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n";
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been \
coming for years whereas you started working here since last month.\n";
}

void	Harl::error()
{
	std::cout << "This is unacceptable ! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (mod[i] == level)
			return ((this->*funcs[i])());
		i++;
	}
}
