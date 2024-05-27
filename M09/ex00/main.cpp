/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:02:24 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/27 18:43:29 by tlegrand         ###   ########.fr       */
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
        std::cerr << "Error: need ONE input file" << std::endl;
        return (1);
    }
    
    BitcoinExchange bank;

    try 
    {
        bank.loadPriceDb("data.csv");
        bank.compute(arg[1]);
    }
    catch (std::runtime_error & error)
    {
        bank.error(error.what());
        return(1);
    }

    

    
	return (0);
}
