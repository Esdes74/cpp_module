/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:07:39 by eslamber          #+#    #+#             */
/*   Updated: 2024/06/19 10:48:34 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL - 1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

// #include "Array.hpp"
// #include <iostream>

// int	main()
// {
// 	Array<int>	test;

// 	try
// 	{
// 		std::cout << "------------------ Premier test ---------------" << std::endl;
// 		std::cout << test[0] << std::endl;
// 		test[0] = 5;
// 		std::cout << test[0] << std::endl;
// 		std::cout << test[1]  << std::endl;
// 	}
// 	catch (const std::exception &expt)
// 	{
// 		std::cerr << "Error : " << expt.what() << std::endl;
// 	}

// 	Array<std::string>	test2(3);

// 	try
// 	{
// 		test2[0] = "Bonjour";
// 		test2[1] = "je m'appel";
// 		test2[2] = "Gertrude";
// 		std::cout << "------------------ Second test ---------------" << std::endl;
// 		std::cout << test2[0] << std::endl;
// 		std::cout << test2[1] << std::endl;
// 		std::cout << test2[2] << std::endl;
// 	}
// 	catch (const std::exception &expt)
// 	{
// 		std::cerr << "Error : " << expt.what() << std::endl;
// 	}
// 	return (0);
// }
