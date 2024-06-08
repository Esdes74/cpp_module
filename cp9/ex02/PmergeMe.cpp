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
// static void	print_vector(std::ostream &os, const std::vector<std::pair<int, int> > &vec);
static void	make_vector_pair(const std::vector<int> &vec, std::vector<std::pair<int, int> > &vec_pair);
static void	make_list_pair(const std::list<int> &lst, std::list<std::pair<int, int> > &lst_pair);
static void	pre_sort(std::vector<int> &vec_after, std::vector<std::pair<int, int> > &vec_pair);
static void	pre_sort(std::list<int> &lst_after, std::list<std::pair<int, int> > &lst_pair);
static void	dicho(std::vector<int>::iterator &it, const std::vector<int> &vec, const int &elem);
static void	dicho(std::list<int>::iterator &it, const std::list<int> &lst, const int &elem);
static void	final_sort(std::vector<int> &_vecAfter, std::vector<std::pair<int, int> > &_vecPair);

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
	make_vector_pair(_vec, _vecPair);
	pre_sort(_vecAfter, _vecPair);
	final_sort(_vecAfter, _vecPair);
	end_vec = clock();
	_timeVec = double(end_vec - start_vec) / CLOCKS_PER_SEC;
	start_lst = clock();
	// Todo: finir l'algo de trie de la liste
	make_list_pair(_lst, _lstPair);
	pre_sort(_lstAfter, _lstPair); // TODO: faire une impression de la liste pour voir
								   // si tous va bien (refaire une fonction print_vector 
								   // dans la surcharge <<)
								   // /!\ IMPRIMER aussi _lstPair
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
	// Ajoute une paire spéciale pour l'element solo si la taille est impaire
	if (vec.size() % 2 == 1)
		vec_pair.push_back(std::make_pair(vec[i],vec[i]));
}

static void	make_list_pair(const std::list<int> &lst, std::list<std::pair<int, int> > &lst_pair)
{
	std::list<int>::const_iterator	it;
	std::list<int>::const_iterator	it_n;
	std::list<int>::const_iterator	end;

	it = lst.begin();
	it_n = lst.begin();
	std::advance(it_n, 1);
	end = lst.end();
	std::advance(end, -1);
	while (it != end)
	{
		lst_pair.push_back(std::make_pair(std::min(*it, *it_n), std::max(*it, *it_n)));
		std::advance(it, 2);
		std::advance(it_n, 2);
	}
	// Ajoute une paire spéciale pour l'element solo si la taille est impaire
	if (lst.size() % 2 == 1)
		lst_pair.push_back(std::make_pair(*it, *it));
}

// Trie les plus grands éléments de chaque paire de int dans le vecteur _vecPair
// Supprime les paire obsoletes
static void	pre_sort(std::vector<int> &vec_after, std::vector<std::pair<int, int> > &vec_pair)
{
	size_t										i;
	size_t										save_i;
	std::vector<int>::iterator					it;
	std::vector<std::pair<int, int> >::iterator	it_p;

	vec_after.push_back(vec_pair[0].second);
	save_i = 0;
	i = 1;
	while (i < vec_pair.size())
	{
		it = vec_after.begin();
		dicho(it, vec_after, vec_pair[i].second);	// Appel de l'algo de recherche dichotomique pour inserer l'element
		if (it == vec_after.begin())
			save_i = i;								// Récupération de l'indice de la premiere paire
		vec_after.insert(it, vec_pair[i].second);
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

static void	pre_sort(std::list<int> &lst_after, std::list<std::pair<int, int> > &lst_pair)
{
	size_t										i;
	size_t										save_i;
	std::list<int>::iterator					it;
	std::list<std::pair<int, int> >::iterator	it_p;

	it_p = lst_pair.begin();
	lst_after.push_back(it_p->second);
	save_i = 0;
	std::advance(it_p, 1);
	i = 1;
	while (it_p != lst_pair.end())
	{
		it = lst_after.begin();
		dicho(it, lst_after, it_p->second);	// Appel de l'algo de recherche dichotomique pour inserer l'element
		if (it == lst_after.begin())
			save_i = i;								// Récupération de l'indice de la premiere paire
		lst_after.insert(it, it_p->second);
		std::advance(it_p, 1);
		i++;
	}

	// Ajout du min de la premiere paire si c'est pas le solo
	// Puis suppression de cette paire
	it_p = lst_pair.begin();
	std::advance(it_p, save_i);
	if (it_p->first != it_p->second)
	{
		lst_after.insert(lst_after.begin(), it_p->first);
		lst_pair.erase(it_p);				// Suppression de la paire la plus petite (plus besoin)
	}

	// Suppression du solo s'il y en a un
	it_p = lst_pair.end();
	std::advance(it_p, -1);				// Récupération de la derniere paire du vecteur
	if (it_p->first == it_p->second)	// Si c'est un tous seul (si la taille du vecteur est impaire)
		lst_pair.erase(it_p);			// Suppression du solo
}

static void	dicho(std::vector<int>::iterator &it, const std::vector<int> &vec, const int &elem)
{
	size_t	div;
	size_t	i;

	div = 2;
	i = vec.size() / div;
	while (i < vec.size())
	{
		if (elem < vec[i])
		{
			if ((i != 0 && elem > vec[i - 1]) || (i == 0))
			{
				it += i;
				return ;
			}
			div *= 2;
			i -= std::max((int) (vec.size() / div), 1);
		}
		else
		{
			div *= 2;
			i += std::max((int) (vec.size() / div), 1);
		}
	}
	it += i;
}

static void	dicho(std::list<int>::iterator &it, const std::list<int> &lst, const int &elem)
{
	size_t							div;
	size_t							i;
	std::list<int>::const_iterator	it_l;

	div = 2;
	i = lst.size() / div;
	while (i < lst.size())
	{
		it_l = lst.begin();
		std::advance(it_l, i);
		if (elem < *it_l)
		{
			std::advance(it_l, -1);
			if ((i != 0 && elem > *it_l) || (i == 0))
			{
				std::advance(it, i);
				return ;
			}
			div *= 2;
			i -= std::max((int) (lst.size() / div), 1);
		}
		else
		{
			div *= 2;
			i += std::max((int) (lst.size() / div), 1);
		}
	}
	std::advance(it, i);
}

static void	final_sort(std::vector<int> &vec_after, std::vector<std::pair<int, int> > &vec_pair)
{
	int											flag;
	int											i;
	size_t										ind_suit;
	size_t										nb_ite;
	std::vector<int>::iterator					it;
	std::vector<std::pair<int, int> >::iterator	it_p;

	ind_suit = 2;
	flag = 0;
	nb_ite = 1;
	i = 1;
	while (flag == 0)
	{
		// Fin du parcourt de vec_pair car arrivé a la fin
		if (ind_suit > vec_pair.size())
		{
			i = vec_pair.size() - 1;
			flag = 1;
		}
		while (i >= 0)
		{
			it = vec_after.begin();
			it_p = vec_pair.begin() + static_cast<size_t>(i);
			dicho(it, vec_after, it_p->first);
			vec_after.insert(it, it_p->first);
			vec_pair.erase(it_p);
			i--;
		}
		nb_ite++;
		ind_suit = (2 ^ nb_ite) - ind_suit;
		i = ind_suit - 1;
	}
}

// static void	print_vector(std::ostream &os, const std::vector<std::pair<int, int> > &vec)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < vec.size())
// 	{
// 		os << "(" << vec[i].first << ", " << vec[i].second << ") ";
// 		i++;
// 	}
// }