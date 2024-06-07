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

static void	print_vector(std::ostream &os, const std::vector<int> &vec);
static void	print_vector(std::ostream &os, const std::vector<std::pair<int, int> > &vec);
static void	make_vector_pair(const std::vector<int> &vec, std::vector<std::pair<int, int> > &vec_pair);
static void	pre_sort(std::vector<int> &vec_after, std::vector<std::pair<int, int> > &vec_pair);
// static void	pre_sort(std::vector<int> &vec_after, const std::vector<std::pair<int, int> > &vec_pair);

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

const std::vector<std::pair<int, int> >	&PmergeMe::getVecPair() const
{
	return (this->_vecPair);
}

const std::list<int>	&PmergeMe::getLst() const
{
	return (this->_lst);
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
void		PmergeMe::pushNumber(int nb)
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
	// Todo: finir l'algo de trie du vecteur
	make_vector_pair(_vec, _vecPair);
	pre_sort(_vecAfter, _vecPair);
	end_vec = clock();
	_timeVec = double(end_vec - start_vec) / CLOCKS_PER_SEC;
	start_lst = clock();
	// Todo: faire l'algo de trie de la liste
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
	print_vector(os, out.getVecPair());
	os << std::endl << "Time to process a range of " << out.getVec().size();
	os << " elements with std::vector : " << out.getTimeVec() << " us\n";
	os << "Time to process a range of " << out.getLst().size();
	os << " elements with std::list : " << out.getTimeLst() << " us";
	return (os);
}

static void	print_vector(std::ostream &os, const std::vector<int> &vec)
{
	size_t	i;

	i = 0;
	while (i < vec.size())
	{
		os << vec[i] << " ";
		i++;
	}
}

static void	make_vector_pair(const std::vector<int> &vec, std::vector<std::pair<int, int> > &vec_pair)
{
	size_t	i;

	i = 0;
	while (i < vec.size() - 1)
	{
		vec_pair.push_back(std::make_pair(std::min(vec[i], vec[i + 1]), std::max(vec[i], vec[i + 1])));
		i += 2;
	}
	// Ajoute une paire spéciale pour le nombre solo si la taille est impaire
	if (vec.size() % 2 == 1)
		vec_pair.push_back(std::make_pair(vec[i],vec[i]));
}

// Trie les plus grands éléments de chaque paire de int dans le vecteur _vecPair
// Supprime les paire obsoletes
static void	pre_sort(std::vector<int> &vec_after, std::vector<std::pair<int, int> > &vec_pair)
{
	int											flag;
	size_t										i;
	size_t										save_i;
	std::vector<int>::iterator					it;
	std::vector<std::pair<int, int> >::iterator	it_p;

	vec_after.push_back(vec_pair[0].second);
	save_i = 0;
	i = 1;
	while (i < vec_pair.size())
	{
		flag = 0;
		it = vec_after.begin();
		while (flag == 0 && it != vec_after.end())
		{
			if (vec_pair[i].second < *it)
			{
				if ((it != vec_after.begin() && vec_pair[i].second > *(it - 1)) \
				|| it == vec_after.begin())
				{
					flag = 1;
					if (it == vec_after.begin())
						save_i = i; // Récupération de l'indice de la premiere paire
					vec_after.insert(it, vec_pair[i].second);
				}
			}
			it++;
		}
		if (it == vec_after.end())
			vec_after.push_back(vec_pair[i].second);
		i++;
	}

	// Ajout du min de la premiere paire si c'est pas le solo
	// Puis suppression de cette paire
	if (vec_pair[save_i].first != vec_pair[save_i].second)
	{
		vec_after.insert(vec_after.begin(), vec_pair[save_i].first);
		it_p = vec_pair.begin() + save_i;	// Récuperation de l'iterateur de la paire la plus petite
		vec_pair.erase(it_p);				// Suppression de la paire la plus petite (plus besoin)
	}

	// Suppression du solo s'il y en a un
	it_p = vec_pair.end();
	it_p--;								// Récupération de la derniere paire du vecteur
	if (it_p->first == it_p->second)	// Si c'est un tous seul (si la taille du vecteur est impaire)
		vec_pair.erase(it_p);			// Suppression du solo
}

static void	print_vector(std::ostream &os, const std::vector<std::pair<int, int> > &vec)
{
	size_t	i;

	i = 0;
	while (i < vec.size())
	{
		os << "(" << vec[i].first << ", " << vec[i].second << ") ";
		i++;
	}
}