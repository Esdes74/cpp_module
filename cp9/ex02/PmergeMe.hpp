/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:02:21 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/05 16:11:42 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iostream>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::vector<int>	_vecAfter;
		std::list<int>		_lst;
		std::list<int>		_lstAfter;
		double				_timeVec;
		double				_timeLst;
	
	public:
		// Constructeur
		PmergeMe();
		PmergeMe(const PmergeMe &cpy);

		// Surcharge d'operateur
		PmergeMe				&operator=(const PmergeMe &cpy);

		// Getters
		const std::vector<int>	&getVec() const;
		const std::vector<int>	&getVecAfter() const;
		const std::list<int>	&getLst() const;
		const double			&getTimeVec() const;
		const double			&getTimeLst() const;
		
		// Fonctions membres
		void					pushNumber(int nb);
		void					sort();

		// Destructeur
		~PmergeMe();
};

std::ostream	&operator<<(std::ostream &os, const PmergeMe &out);
std::ostream	&operator<<(std::ostream &os, PmergeMe &out);

#endif