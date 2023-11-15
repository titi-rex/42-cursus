/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:59:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/15 22:11:11 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 75

class Aw
{
	int	_n;
	public:
		Aw(void) : _n(42) {};
		int get(void) const {return (_n);}
};

std::ostream & operator<<(std::ostream & o, Aw const & rhs) {o << rhs.get(); return o;};



int	main(void)
{
	try
	{
		Array<Aw>	arraw(5);
		for (int i = 0; i < MAX_VAL; ++i)
    	{
			std::cout << arraw[i].get() << " ";
    	}
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		e.what();
	}
	
	std::cout << "test construction " << std::endl;
	{
		Array<int>	empty;
		Array<int>	base(17);
		
		std::cout << "size of empty " << empty.size() << std::endl;
		print_arr(empty);
		std::cout << "size of base " << base.size() << std::endl;
		print_arr(base);
	}
	
	Array<int>	numbers(MAX_VAL);
	int*		control = new int[MAX_VAL];
    std::srand(time(NULL));
	
 	for (int i = 0; i < MAX_VAL; ++i)
    {
        const int value = std::rand();
        numbers[i] = value;
        control[i] = value;
    }
   for (int i = 0; i < MAX_VAL; ++i)
    {
        if (control[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
			delete[] control;
            return 1;
        }
    }
	std::cout << "test wrong acces " << std::endl;
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
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << "test copy " << std::endl;

    for (int i = 0; i < MAX_VAL; ++i)
    {
        numbers[i] = std::rand() % 151 + 1;
		control[i] = 0;
    }
	{
		Array<int>	cpy;

		cpy = numbers;
		for (size_t i = 0; i < cpy.size(); ++i)
		{
			if (cpy[i] != numbers[i])
			{
				std::cout << "ERROR copy failed at i " << i << std::endl;
				break ;
			}
		}
	}
	print_arr(numbers);
	std::cout << std::endl;	
	for (int i = 0; i < MAX_VAL; ++i)
    {
		std::cout << control[i] << " ";
    }
	std::cout << std::endl;	
	for (int i = 0; i < MAX_VAL; ++i)
    {
        if (control[i] == numbers[i])
        {
            std::cerr << "numbers wrong value!!" << std::endl;
			break ;
        }
    }
	delete[] control;
	
	return (0);
}
