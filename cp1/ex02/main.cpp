/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:27:00 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/18 09:42:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

using namespace std;

int	main()
{
	string	test;
	string	*stringPTR;
	string	&stringREF(test);

	test = "HI THIS IS BRAIN";
	stringPTR = &test;

	cout << "L'adresse de la string est : " << &test << endl;
	cout << "L'adresse stockée dans stringPTR est : " << stringPTR << endl;
	cout << "L'adresse stockée dans stringREF est : " << &stringREF << endl << endl;

	cout << "La valeur stockée dans la string est : " << test << endl;
	cout << "La valeur pointée par le pointeur stringPTR est : " << *stringPTR \
		<< endl;
	cout << "La valeur pointée par stringREF est : " << stringREF << endl;
}
