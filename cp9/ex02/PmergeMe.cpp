/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:02:01 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/05 16:28:05 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <iostream>

static void	print_vector(std::ostream &os, std::vector<int> vec);

// Constructeur
PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
	*this = cpy;
}

// Surcharge d'operateur
PmergeMe	&PmergeMe::operator=(const PmergeMe &cpy) // Todo: Verifier que cela fasse bien une copie profonde
{
	if (this != &cpy)
	{
		_vec = cpy._vec;
		_vecAfter = cpy._vecAfter;
		_lst = cpy._lst;
		_lstAfter = cpy._lstAfter;
		_timeVec = cpy._timeVec;
		_timeLst = cpy._timeLst;
	}
	return (*this);
}

const std::vector<int>	&PmergeMe::getVec() const
{
	return (this->_vec);
}

const std::vector<int>	&PmergeMe::getVecAfter() const
{
	return (this->_vecAfter);
}

const std::list<int>	&PmergeMe::getLst() const
{
	return (this->_lst);
}

const double			&PmergeMe::getTimeVec() const
{
	return (this->_timeVec);
}

const double			&PmergeMe::getTimeLst() const
{
	return (this->_timeLst);
}

// Fonctions membres
void		PmergeMe::pushNumber(int nb)
{
	_vec.push_back(nb);
	_lst.push_back(nb);
}

void		PmergeMe::sort()
{
	clock_t	start_vec;
	clock_t	end_vec;
	clock_t	start_lst;
	clock_t	end_lst;

	start_vec = clock();
	// Todo: faire l'algo de trie du vecteur
	end_vec = clock();
	_timeVec = double(end_vec - start_vec) / CLOCKS_PER_SEC;
	start_lst = clock();
	// Todo: faire l'algo de trie de la liste
	end_lst = clock();
	_timeLst = double(end_lst - start_lst) / CLOCKS_PER_SEC;
}

// Destructeur
PmergeMe::~PmergeMe()
{
}

std::ostream	&operator<<(std::ostream &os, const PmergeMe &out)
{
	os << "Before: ";
	print_vector(os, out.getVec());
	os << std::endl << "After: ";
	print_vector(os, out.getVecAfter());
	os << std::endl << "Time to process a range of " << out.getVec().size();
	os << " elements with std::vector : " << out.getTimeVec() << " us\n";
	os << std::endl << "Time to process a range of " << out.getLst().size();
	os << " elements with std::list : " << out.getTimeLst() << " us\n";
	return (os);
}

std::ostream	&operator<<(std::ostream &os, PmergeMe &out)
{
	os << "Before: ";
	print_vector(os, out.getVec());
	os << std::endl << "After: ";
	print_vector(os, out.getVecAfter());
	os << std::endl << "Time to process a range of " << out.getVec().size();
	os << " elements with std::vector : " << out.getTimeVec() << " us\n";
	os << "Time to process a range of " << out.getLst().size();
	os << " elements with std::list : " << out.getTimeLst() << " us";
	return (os);
}

static void	print_vector(std::ostream &os, std::vector<int> vec)
{
	size_t	i;

	i = 0;
	while (i < vec.size())
	{
		os << vec[i] << " ";
		i++;
	}
}
