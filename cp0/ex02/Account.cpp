/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:44:47 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/17 10:49:52 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

void	Account::displayAccountsInfos( void )
{
}

Account::Account( int initial_deposit )
{
	this->_totalAmount = initial_deposit;
}

Account::~Account( void )
{
}

void	Account::makeDeposit( int deposit )
{
	(void) deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	(void) withdrawal;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (0);
}

void	Account::displayStatus( void ) const
{
}
