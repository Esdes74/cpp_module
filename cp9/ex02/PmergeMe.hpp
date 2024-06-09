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
# include <stdexcept>
# include <utility>

class PmergeMe
{
	private:
		double								_timeVec;
		double								_timeLst;
		std::vector<int>					_vec;
		std::vector<int>					_vecAfter;
		std::vector<std::pair<int, int> >	_vecPair;
		std::list<int>						_lst;
		std::list<int>						_lstAfter;
		std::list<std::pair<int, int> >		_lstPair;
	
	public:
		// Constructeur
		PmergeMe();
		PmergeMe(const PmergeMe &cpy);

		// Surcharge d'operateur
		PmergeMe								&operator=(const PmergeMe &cpy);

		// Getters
		const std::vector<int>					&getVec() const;
		const std::vector<int>					&getVecAfter() const;
		const std::vector<std::pair<int, int> >	&getVecPair() const;
		const std::list<int>					&getLst() const;
		const std::list<int>					&getLstAfter() const;
		const std::list<std::pair<int, int> >	&getLstPair() const;
		const double							&getTimeVec() const;
		const double							&getTimeLst() const;
		
		// Fonctions membres
		void									pushNumberThrow(int nb);
		void									sort();

		// Classes d'exceptions
		class DoubleException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		// Destructeur
		~PmergeMe();
};

template <typename C, typename DC>
void	make_pair_list(const C &lst, DC &lst_pair)
{
	typename C::const_iterator	it;
	typename C::const_iterator	it_n;
	typename C::const_iterator	end;

	it = lst.begin();
	it_n = lst.begin();
	std::advance(it_n, 1);
	end = lst.end();
	std::advance(end, -1);
	while (it != end && it_n != end)
	{
		lst_pair.push_back(std::make_pair(std::min(*it, *it_n), std::max(*it, *it_n)));
		std::advance(it, 2);
		std::advance(it_n, 2);
	}
	// Ajoute une paire spéciale pour l'element solo si la taille est impaire
	if (lst.size() % 2 == 1)
		lst_pair.push_back(std::make_pair(*it, *it));
}

template <typename C>
void	dicho(typename C::iterator &it, const C &lst, const int &elem)
{
	size_t						div;
	size_t						i;
	typename C::const_iterator	it_l;

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

// Trie les plus grands éléments de chaque paire de int dans le vecteur _vecPair
// Supprime les paire obsoletes
template <typename C, typename DC>
static void	pre_sort(C &lst_after, DC &lst_pair)
{
	size_t					i;
	size_t					save_i;
	typename C::iterator	it;
	typename DC::iterator	it_p;

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
			save_i = i;						// Récupération de l'indice de la premiere paire
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
		lst_pair.erase(it_p);	// Suppression de la paire la plus petite (plus besoin)
	}

	// Suppression du solo s'il y en a un
	it_p = lst_pair.end();
	std::advance(it_p, -1);				// Récupération de la derniere paire du vecteur
	if (it_p->first == it_p->second)	// Si c'est un tous seul (si la taille du vecteur est impaire)
		lst_pair.erase(it_p);			// Suppression du solo
}

template <typename C, typename DC>
static void	final_sort(C &vec_after, DC &vec_pair)
{
	int						flag;
	int						i;
	size_t					ind_suit;
	size_t					nb_ite;
	typename C::iterator	it;
	typename DC::iterator	it_p;

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
			it_p = vec_pair.begin();
			std::advance (it_p, i);
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

template <typename C>
static void	print(std::ostream &os, const C &vec)
{
	typename C::const_iterator	it;

	it = vec.begin();
	while (it != vec.end())
	{
		os << *it << " ";
		std::advance(it, 1);
	}
}

template <typename P>
static void	print_pair(std::ostream &os, const P &vec)
{
	typename P::const_iterator	it;

	it = vec.begin();
	while (it != vec.end())
	{
		os << "(" << it->first << ", " << it->second << ") ";
		std::advance(it, 1);
	}
}

std::ostream	&operator<<(std::ostream &os, const PmergeMe &out);
std::ostream	&operator<<(std::ostream &os, PmergeMe &out);

#endif