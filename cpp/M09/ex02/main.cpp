/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:02:24 by tlegrand          #+#    #+#             */
/*   Updated: 2024/06/06 11:12:13 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char** arg)
{
    if (ac <= 2)
    {
        std::cerr << "Error: not enough numbers provided" << std::endl;
        return (1);
    }

    PmergeMe            m(false);
    std::vector<int>    v_input;
    std::vector<int>    v_sorted;
    std::deque<int>     d_input;
    std::deque<int>     d_sorted;

    for (int i = 1; i < ac; ++i)
    {
        int tmp = std::atoi(arg[i]);
        if (tmp < 0)
        {
            std::cerr << "Error : invalid input: " << tmp << std::endl;
            return (1);
        }
        if (std::find(v_input.begin(), v_input.end(), tmp) != v_input.end())
        {
            std::cerr << "Error : no duplicate allowed: " << tmp << std::endl;
            return (1);
        }
        v_input.push_back(tmp);
        d_input.push_back(tmp);
    }

    std::cout << "Input: (size: " << v_input.size() << ") ";
    printContainer(v_input);

    double v_time = m.timer(v_input, v_sorted) / CLOCKS_PER_SEC;
    double d_time = m.timer(d_input, d_sorted) / CLOCKS_PER_SEC;
    
    validate(v_input, v_sorted);
    std::cout << "Sorted: (size: " << v_sorted.size() << ") ";
    printContainer(v_sorted);
    std::cout << "Container: vector, time for " << v_sorted.size() << " elements: ";
    std::cout << std::fixed << std::setprecision(6) << v_time << "us" << std::endl;

    validate(d_input, d_sorted);
    std::cout << "Container: deque, time for " << d_sorted.size() << " elements: ";
    std::cout << std::fixed << std::setprecision(6) << d_time << "us" << std::endl;

    return (0);
}
