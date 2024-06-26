/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:02:21 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/26 15:55:31 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iostream>
# include <stdexcept>
# include <algorithm>
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

		class CaractereException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class NegativeNumberException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		// Destructeur
		~PmergeMe();
};

template <typename C, typename DC>
void	make_pair_list(const C &cont, DC &lpair)
{
	typename C::const_iterator	it;
	typename C::const_iterator	it_n;
	typename C::const_iterator	end;

	it = cont.begin();
	it_n = cont.begin();
	std::advance(it_n, 1);
	end = cont.end();
	while (it != end && it_n != end)
	{
		lpair.push_back(std::make_pair(std::min(*it, *it_n), std::max(*it, *it_n)));
		std::advance(it, 2);
		std::advance(it_n, 2);
	}
	// Ajoute une paire spéciale pour l'element solo si la taille est impaire
	if (cont.size() % 2 == 1)
		lpair.push_back(std::make_pair(*it, *it));
}

template <typename C>
void	dicho(typename C::iterator &it, const C &lst, const long int &len, const int &elem)
{
	size_t						div;
	long int					i;
	typename C::const_iterator	it_l;

	div = 2;
	i = len / div;
	while (i < len)
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
			i -= std::max((int) (len / div), 1);
		}
		else
		{
			div *= 2;
			i += std::max((int) (len / div), 1);
		}
	}
	std::advance(it, i);
}

// Trie les plus grands éléments de chaque paire de int dans le vecteur _vecPair
// Supprime les paire obsoletes
template <typename C, typename DC>
void	pre_merge(C &after, DC &pair)
{
	typename C::iterator	it_a;
	typename C::iterator	it_sa;
	typename DC::iterator	it_p;

	it_p = pair.begin();
	while (it_p != pair.end())
	{
		after.push_back(it_p->second);					// Creer la liste a merge
		std::advance(it_p, 1);
	}
	it_a = after.begin();
	it_sa = after.begin();
	std::advance(it_sa, 1);
	while (it_a != after.end() && it_sa != after.end())	// Boucle qui trie deux par deux
	{
		if (*it_a >= *it_sa)
			std::iter_swap(it_a, it_sa);
		std::advance(it_a, 2);
		std::advance(it_sa, 2);
	}
}

template <typename T>
void	merge_sort(T &after)
{
	int							flag;
	size_t						jump;
	size_t						i;
	T						save(after.size());
	typename T::iterator	it_save;
	typename T::iterator	first;
	typename T::iterator	second;
	typename T::iterator	end;

	jump = 1;
	while (jump < after.size())
	{
		save = after;
		flag = 0;
		i = 0;
		it_save = save.begin();
		first = after.begin();
		second = first;
		end = first;
		do
		{
			if (i + jump + 1 < after.size() && flag == 0)
			{
				second = first;
				std::advance(second, jump + 1);
				i += jump + 1;
			}
			else
			{
				flag = 1;
				second = after.end();
				i = after.size();
				end = second;
			}
			if (i + jump + 1 < after.size() && flag == 0)
			{
				end = second;
				std::advance(end, jump + 1);
				i += jump + 1;
			}
			else if (flag != 1)
			{
				flag = 2;
				end = after.end();
				i = after.size();
			}
			if (flag != 1)
			{
				std::merge(first, second, second, end, it_save);
				if (i + 1 < after.size())
				{
					first = end;
					std::advance(it_save, 2 * jump + 2);
				}
			}
			std::copy(save.begin(), it_save, after.begin());
		}
		while (flag == 0);
		jump = jump * 2 + 1;
		after = save;
	}
}

// Trie les plus grands éléments de chaque paire de int dans le vecteur _vecPair
// Supprime les paire obsoletes
template <typename C, typename DC>
void	post_merge(C &after, DC &pair)
{
	typename C::iterator	it;
	typename DC::iterator	it_p;

	// it_p = pair.begin();
	// after.push_back(it_p->second);
	// save_i = 0;
	// std::advance(it_p, 1);
	// i = 1;
	// while (it_p != pair.end())
	// {
	// 	it = after.begin();
	// 	dicho(it, after, it_p->second);	// Appel de l'algo de recherche dichotomique pour inserer l'element
	// 	if (it == after.begin())
	// 		save_i = i;						// Récupération de l'indice de la premiere paire
	// 	after.insert(it, it_p->second);
	// 	std::advance(it_p, 1);
	// 	i++;
	// }

	// Recherche la paire du premier element de la liste after
	it_p = pair.begin();
	it = after.begin();
	while (it_p->second != *it)
		std::advance(it_p, 1);

	// Ajout du min de la premiere paire si c'est pas le solo
	// Puis suppression de cette paire
	if (it_p->first != it_p->second)
	{
		after.insert(after.begin(), it_p->first);
		pair.erase(it_p);	// Suppression de la paire la plus petite (plus besoin)
	}

	// Suppression du solo s'il y en a un
	it_p = pair.end();
	std::advance(it_p, -1);				// Récupération de la derniere paire du vecteur
	if (it_p->first == it_p->second)	// Si c'est un tous seul (si la taille du vecteur est impaire)
		pair.erase(it_p);				// Suppression du solo
}

// TODO: ecrire une fonction qui renvois l'indice auquel est l'element recherchee
// arg : int elem (element recherchee dans le conteneur)
//		 T cont (conteneur dans lequel l'element va pouvoir etre recherchee)
template <typename C>
long int	find_index(const C &cont, int elem)
{
	size_t						len;
	typename C::const_iterator	it;

	it = cont.begin();
	len = 0;
	while (it != cont.end())
	{
		if (*it == elem)
			return (len);
		std::advance(it, 1);
		len++;
	}
	return (-1);
}

template <typename C, typename DC>
void	final_sort(C &after, DC &pair)
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
		// Fin du parcourt de pair car arrivé a la fin
		if (ind_suit > pair.size())
		{
			i = pair.size() - 1;
			flag = 1;
		}
		while (i >= 0)
		{
			it = after.begin();
			it_p = pair.begin();
			std::advance (it_p, i);
			dicho(it, after, find_index(after, it_p->second), it_p->first);
			after.insert(it, it_p->first);
			pair.erase(it_p);
			i--;
		}
		nb_ite++;
		ind_suit = (2 ^ nb_ite) - ind_suit;
		i = ind_suit - 1;
	}
}

template <typename C>
void	print(std::ostream &os, const C &cont)
{
	typename C::const_iterator	it;

	it = cont.begin();
	while (it != cont.end())
	{
		os << *it << " ";
		std::advance(it, 1);
	}
}

template <typename P>
void	print_pair(std::ostream &os, const P &cont)
{
	typename P::const_iterator	it;

	it = cont.begin();
	while (it != cont.end())
	{
		os << "(" << it->first << ", " << it->second << ") ";
		std::advance(it, 1);
	}
}

std::ostream	&operator<<(std::ostream &os, const PmergeMe &out);
std::ostream	&operator<<(std::ostream &os, PmergeMe &out);

#endif