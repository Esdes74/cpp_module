/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:31:34 by eslamber          #+#    #+#             */
/*   Updated: 2024/02/22 15:22:44 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	h;

	if (ac == 1)
	{
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
	}
	else if (ac == 2)
		h.complain(av[1]);
	return (0);
}
