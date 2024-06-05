/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:00:44 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/05 15:11:17 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>

class RPN
{
	private:
		std::stack<int>	_stk;

	public:
		// Constructeur
		RPN();
		RPN(const RPN &cpy);

		// Surcharge d'operateur
		RPN		&operator=(const RPN &cpy);

		// Fonctions membres
		void	pushNumber(int nb);
		void	addNumber();
		void	mulNumber();
		void	divNumber();
		void	susNumber();
		void	printRes();

		// Destructeur
		~RPN();
};

#endif