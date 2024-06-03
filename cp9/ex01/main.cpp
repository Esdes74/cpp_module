/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:58:48 by eslamber          #+#    #+#             */
/*   Updated: 2024/05/06 12:00:23 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main()
{
	RPN	test;

	test.pushNumber(2);
	test.pushNumber(10);
	test.divNumber();
	test.printRes();
	return (0);
}