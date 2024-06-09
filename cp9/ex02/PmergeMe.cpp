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
#include <algorithm>

// Constructeur
PmergeMe::PmergeMe()
	:_timeVec(0), _timeLst(0)
{
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
	:_timeVec(0), _timeLst(0)
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

const std::vector<std::pair<int, int> >	&PmergeMe::getVecPair() const
{
	return (this->_vecPair);
}

const std::list<int>	&PmergeMe::getLst() const
{
	return (this->_lst);
}

const std::list<int>	&PmergeMe::getLstAfter() const
{
	return (this->_lstAfter);
}

const std::list<std::pair<int, int> >	&PmergeMe::getLstPair() const
{
	return (this->_lstPair);
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
void		PmergeMe::pushNumberThrow(int nb)
{
	std::vector<int>::iterator	it;
	it = std::find(_vec.begin(), _vec.end(), nb);
	if (it != _vec.end())
		throw PmergeMe::DoubleException();
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
	make_pair_list(_vec, _vecPair);
	pre_sort(_vecAfter, _vecPair);
	final_sort(_vecAfter, _vecPair);
	end_vec = clock();
	_timeVec = double(end_vec - start_vec) / CLOCKS_PER_SEC;
	start_lst = clock();
	make_pair_list(_lst, _lstPair);
	pre_sort(_lstAfter, _lstPair);
	final_sort(_lstAfter, _lstPair);
	end_lst = clock();
	_timeLst = double(end_lst - start_lst) / CLOCKS_PER_SEC;
}

// Classe d'exception
const char	*PmergeMe::DoubleException::what() const throw()
{
	return ("Error: There is double");
}

// Destructeur
PmergeMe::~PmergeMe()
{
}

// Surcharge d'operateur d'impression
std::ostream	&operator<<(std::ostream &os, const PmergeMe &out)
{
	os << "Before: ";
	print(os, out.getVec());
	os << std::endl << "After: ";
	print(os, out.getLstAfter());
	os << std::endl << "Time to process a range of " << out.getVec().size();
	os << " elements with std::vector : " << out.getTimeVec() << " us\n";
	os << std::endl << "Time to process a range of " << out.getLst().size();
	os << " elements with std::list : " << out.getTimeLst() << " us\n";
	return (os);
}

std::ostream	&operator<<(std::ostream &os, PmergeMe &out)
{
	os << "Before: ";
	print(os, out.getVec());
	os << std::endl << "After: ";
	print(os, out.getLstAfter());
	os << std::endl << "Time to process a range of " << out.getVec().size();
	os << " elements with std::vector : " << out.getTimeVec() << " us\n";
	os << "Time to process a range of " << out.getLst().size();
	os << " elements with std::list : " << out.getTimeLst() << " us";
	return (os);
}
