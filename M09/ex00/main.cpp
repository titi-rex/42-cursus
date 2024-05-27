/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:02:24 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/27 15:16:05 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstring>

#include "BitcoinExchange.hpp"


int	main(int ac, char** arg)
{
    if (ac != 2)
    {
        std::cout << "Error: need ONE input file" << std::endl;
        return (1);
    }
    
    BitcoinExchange bank;

    if (bank.loadPriceDb(arg[1]) == false)
    {
        std::cout << "Error: can't open data file" << std::endl;
        return (1);
    }
    
    bank.findPrice(0);
    
	return (0);
}
