/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:02:01 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/26 13:30:46 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <algorithm>

static void	merge_sort(std::vector<int> &After);
// static void	merge_sort(std::list<int> &After);

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
	// clock_t	start_lst;
	// clock_t	end_lst;

	start_vec = clock();
	make_pair_list(_vec, _vecPair);
	pre_merge(_vecAfter, _vecPair);
	merge_sort(_vecAfter);
	post_merge(_vecAfter, _vecPair);
	final_sort(_vecAfter, _vecPair);
	end_vec = clock();
	// _timeVec = double(end_vec - start_vec) / CLOCKS_PER_SEC;
	// start_lst = clock();
	// make_pair_list(_lst, _lstPair);
	// pre_merge(_lstAfter, _lstPair);
	// merge_sort(_lstAfter);
	// post_merge(_lstAfter, _lstPair);
	// final_sort(_lstAfter, _lstPair);
	// end_lst = clock();
	// _timeLst = double(end_lst - start_lst) / CLOCKS_PER_SEC;
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

// static void	merge_sort(std::vector<int> &After)
// {
// 	int							flag;
// 	size_t						jump;
// 	size_t						i;
// 	std::vector<int>			save(After.size());
// 	std::vector<int>::iterator	it_save;
// 	std::vector<int>::iterator	first;
// 	// std::vector<int>::iterator	end_first;
// 	std::vector<int>::iterator	second;
// 	std::vector<int>::iterator	end;
// 	// std::vector<int>::iterator	end_second;

// 	std::vector<int>::iterator	it_test = After.begin();
// 	std::cout << "{";
// 	while (it_test != After.end())
// 	{
// 		std::cout << *it_test << "; ";
// 		it_test++;
// 	}
// 	std::cout << "}\n\n";

// 	jump = 1;
// 	while (jump < After.size())
// 	{
// 		flag = 0;
// 		i = 0;
// 		it_save = save.begin();
// 		first = After.begin();
// 		second = first;
// 		end = first;
// 		do
// 		{
// 			std::vector<int>::iterator	it_test = save.begin();
// 			std::cout << "{";
// 			while (it_test != save.end())
// 			{
// 				std::cout << *it_test << "; ";
// 				it_test++;
// 			}
// 			std::cout << "}\n";
// 			// if (i + jump < After.size())
// 			// {
// 			// 	end_first = first;
// 			// 	std::advance(end_first, jump);
// 			// 	i += jump;
// 			// }
// 			// else
// 			// {
// 			// 	flag = 1;
// 			// 	end_first = After.end();
// 			// 	std::advance(end_first, -1);
// 			// }
// 			if (i + 1 < After.size() && flag == 0)
// 			{
// 				second = first;
// 				std::advance(second, jump + 1);
// 				i++;
// 			}
// 			else
// 			{
// 				flag = 1;
// 				second = After.end();
// 				std::advance(second, -1);
// 			}
// 			if (i + jump < After.size() && flag == 0)
// 			{
// 				end = second;
// 				std::advance(end, jump + 1);
// 				i += jump;
// 			}
// 			else if (flag != 1)
// 			{
// 				flag = 2;
// 				end = After.end();
// 				std::advance(end, -1);
// 			}
// 			// si flag false pas de merge on arrete la et on recommence la boucle de base avec le jump incrementee
// 			// std::cout << "flag = " << flag << " first = " << *first << " end_first = " << *end_first << " second = " << *second << " end_second = " << *end_second << std::endl;
// 			// std::cout << "flag = " << flag << " first = " << *first << " second = " << *second << " end_second = " << *end << std::endl;
// 			if (flag != 1)
// 			{
// 				std::merge(first, second, second, end, it_save);
// 				if (i + 1 < After.size())
// 				{
// 					first = end;
// 					std::advance(it_save, 2 * jump + 2);
// 					first++;
// 				}
// 			}
// 		}
// 		while (flag == 0);
// 		After = save;
// 		// save.clear();
// 		jump = jump * 2 + 1;

// 		// std::cout << "flag = " << flag << std::endl;
// 		// std::vector<int>::iterator	it = After.begin();
// 		// while (it != After.end())
// 		// {
// 		// 	std::cout << *it << "; ";
// 		// 	std::advance(it, 1);
// 		// }
// 		// std::cout << "\n";
// 	}
// }

// static void	merge_sort(std::list<int> &After)
// {
// 	int							flag;
// 	size_t						jump;
// 	size_t						i;
// 	std::list<int>			save;
// 	std::list<int>::iterator	it_save;
// 	std::list<int>::iterator	first;
// 	std::list<int>::iterator	end_first;
// 	std::list<int>::iterator	second;
// 	std::list<int>::iterator	end_second;

// 	jump = 3;
// 	while (jump < After.size())
// 	{
// 		flag = 0;
// 		i = 0;
// 		first = After.begin();
// 		do
// 		{
// 			if (i + jump < After.size())
// 			{
// 				end_first = first;
// 				std::advance(end_first, jump);
// 				i += jump;
// 			}
// 			else
// 			{
// 				flag = 1;
// 				end_first = After.end();
// 			}
// 			if (i + 1 < After.size() && flag == 0)
// 			{
// 				second = end_first;
// 				second++;
// 				i++;
// 			}
// 			else
// 			{
// 				flag = 1;
// 				second = After.end();
// 			}
// 			if (i + jump < After.size() && flag == 0)
// 			{
// 				end_second = second;
// 				std::advance(end_second, jump);
// 				i += jump;
// 			}
// 			else
// 			{
// 				flag = 1;
// 				end_second = After.end();
// 			}
// 			// si flag false pas de merge on arrete la et on recommence la boucle de base avec le jump incrementee
// 			if (flag != 1)
// 			{
// 				it_save = save.begin();
// 				std::merge(first, end_first, second, end_second, it_save);
// 				After = save;
// 				if (i + 1 < After.size())
// 				{
// 					first = end_second;
// 					first++;
// 				}
// 			}
// 		}
// 		while (flag == 0);
// 		jump = jump * 2 + 1;
// 	}
// }

static void	merge_sort(std::vector<int> &After)
{
	int							flag;
	size_t						jump;
	size_t						i;
	std::vector<int>			save(After.size());
	// std::vector<int>			tmp(After.size());
	// std::vector<int>::iterator	it_tmp;
	// std::vector<int>			tmp2(After.size());
	// std::vector<int>::iterator	it_tmp2;
	std::vector<int>::iterator	it_save;
	std::vector<int>::iterator	first;
	std::vector<int>::iterator	second;
	std::vector<int>::iterator	end;

	jump = 1;
	while (jump < After.size())
	{
		flag = 0;
		i = 0;
		it_save = save.begin();
		first = After.begin();
		second = first;
		end = first;
		std::cerr << "jump = " << jump << "\n";
		do
		{
			// std::cerr << "i = " << i << "\n";
			std::vector<int>::iterator	it_test = save.begin();
			std::cout << "{";
			while (it_test != save.end())
			{
				std::cout << *it_test << "; ";
				it_test++;
			}
			std::cout << "}\n";
			if (i + jump + 1 < After.size() && flag == 0)
			{
				second = first;
				std::advance(second, jump + 1);
				i += jump + 1;
				std::cerr << "1) i = " << i << "\n";
			}
			else
			{
				flag = 1;
				second = After.end();
				std::advance(end, -1);
				i = After.size();
				end = second;
			}
			if (i + jump + 1 < After.size() && flag == 0)
			{
				end = second;
				std::advance(end, jump + 1);
				i += jump + 1;
				std::cerr << "2) i = " << i << "\n";
			}
			else if (flag != 1)
			{
				flag = 2;
				end = After.end();
				std::advance(end, -1);
				i = After.size();
			}
			// std::cerr << "flag = " << flag << std::endl;
			std::cout << "flag = " << flag << " first = " << *first << " second = " << *second << " end = " << *end << std::endl;
			if (flag != 1)
			{
				// std::copy(first, second, tmp.begin());
				// it_tmp = tmp.begin();
				// std::advance(it_tmp, jump + 1);
				// std::copy(second, end, tmp2.begin());
				// it_tmp2 = tmp2.begin();
				// std::advance(it_tmp2, jump + 1);
				std::merge(first, second, second, end, it_save);
				// std::merge(tmp.begin(), it_tmp, tmp2.begin(), it_tmp2, it_save);
				if (i + 1 < After.size())
				{
					first = end;
					std::advance(it_save, 2 * jump + 2);
				}
			}
			std::copy(save.begin(), it_save, After.begin());
		}
		while (flag == 0);
		jump = jump * 2 + 1;
	}
	After = save;
	std::vector<int>::iterator	it_test = After.begin();
	std::cout << "[";
	while (it_test != After.end())
	{
		std::cout << *it_test << "; ";
		it_test++;
	}
	std::cout << "]\n";
}