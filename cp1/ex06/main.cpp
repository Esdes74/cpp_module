/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:31:34 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/21 19:02:07 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		cout << "Probably complaining about insignificant problems\n";
		return (1);
	}
	Harl	h(av[1]);

	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERROR");
	h.complain("");
	h.complain("dsbvv dqfq");
	h.complain("DsdfhgbEdfvBqgvUqgGqeg");
	h.complain("D E B U G");
	h.complain("DEB UG");
	h.complain(" ");
	h.complain("\0");
	h.complain("\n");
	h.complain(" ");
	return (0);
}
