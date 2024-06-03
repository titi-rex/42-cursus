/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:02:24 by tlegrand          #+#    #+#             */
/*   Updated: 2024/06/03 14:25:11 by tlegrand         ###   ########.fr       */
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
        v_input.push_back(tmp);
        d_input.push_back(tmp);
    }

    std::cout << "Raw: (size: " << v_input.size() << ") ";
    printContainer(v_input);

    double v_time = m.timer(v_input, v_sorted) / CLOCKS_PER_SEC;
    double d_time = m.timer(d_input, d_sorted) / CLOCKS_PER_SEC;
    
    std::cout << "" << std::endl;
    validate(v_input, v_sorted);
    std::cout << "Container: vector, time for " << v_sorted.size() << " elements: ";
    std::cout << std::fixed << std::setprecision(6) << v_time << "us" << std::endl;
    std::cout << "Sorted: ";
    printContainer(v_sorted);

    validate(d_input, d_sorted);
    std::cout << "Container: deque, time for " << d_sorted.size() << " elements: ";
    std::cout << std::fixed << std::setprecision(6) << d_time << "us" << std::endl;
    std::cout << "Sorted: ";
    printContainer(d_sorted);

    return (0);
}
