/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:02:24 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/28 15:53:47 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char** arg)
{
    if (ac == 1)
    {
        std::cerr << "Error: no number provided" << std::endl;
        return (1);
    }

    std::vector<int>    v;

    for (int i = 1; i < ac; ++i)
    {
        v.push_back(std::atoi(arg[i]));
        
    }
    std::cout << v;
    std::clock_t v_time = timer(v, compute);
    std::cout << std::fixed << std::setprecision(2) << "Time: " << 1000 * v_time / CLOCKS_PER_SEC << std::endl;
	return (0);
}
