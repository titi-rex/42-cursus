/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:02:24 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/28 11:57:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

// number -> push
// op -> apply to last 2 number (pop pop push)


int	main(int ac, char** arg)
{
    if (ac != 2)
        std::cerr << "Error: RPN take ONE string as argument" << std::endl;
    else try 
    {
        std::cout << compute(arg[1]) << std::endl;
	    return (0);
    }
    catch (std::exception & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (1);
}
