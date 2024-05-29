/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:31:18 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/29 15:55:06 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

size_t g_depht = 0;

int&    sort(int& a, int& b)
{
    if (a > b)
        swap(a, b);
    return (b);    
}

void    compute(std::vector<int>& input, std::vector<int>& sorted)
{
    std::vector<int> seq;

    std::cout << std::endl;
     ++g_depht;


    if (input.size() == 2) // stop rec
    {
        std::cout << "d" << g_depht << ": " << "MAX DEPTH REACHED" << std::endl;
        sorted.push_back(input.at(0));
        sorted.push_back(input.at(1));
        sort(sorted.at(0), sorted.at(1));
        std::cout << "d" << g_depht << ": " << "Input: " << input;
        std::cout << "d" << g_depht << ": " << "Sorted: " << sorted;
        std::cout << std::endl;
        --g_depht;
        return ;
    }

    // for each pair: sort inside by max and extarct max to s
    for (size_t i = 0; i < input.size(); i += 2) 
    {
        if (i + 1 == input.size())
        {
            // seq.push_back(input.at(i));
            break ; //one element left should stay in input
        }
        seq.push_back(sort(input.at(i), input.at(i + 1)));
    }
    std::cout << "d" << g_depht << ": " << "Input: " << input;
    std::cout << "d" << g_depht << ": " << "Sequence: " << seq;
    compute(seq, sorted);
    std::cout << "d" << g_depht << ": " << "Input: " << input;
    std::cout << "d" << g_depht << ": " << "Sorted: " << sorted;
    
    // sort all pair by max element based on sorted
    for (size_t i = 0, j = 1; i < sorted.size(); ++i, j += 2)
    {
        std::vector<int>::iterator it = std::find(input.begin(), input.end(), sorted.at(i));
        std::cout << "d" << g_depht << ": " << "Find: " << *it << std::endl;
        if (*it == input.at(j))
        {
            std::cout << "d" << g_depht << ": " << "No swap needed" << std::endl;
            continue;
        }
        std::cout << "d" << g_depht << ": " << "Swap with: " << input.at(j - 1) << " and " << input.at(j)<< std::endl;
        swap(*(it - 1), input.at(j - 1));
        swap(*it, input.at(j));
    }
    std::cout << "d" << g_depht << ": " << "Input pair-sorted: " << input;


    // inject in sorted
    sorted.insert(sorted.begin(), input.at(0));
    std::cout << "d" << g_depht << ": " << "Insert: " << input.at(0)  << std::endl;
    std::cout << "d" << g_depht << ": " << "Sorted: " << sorted;
    for (size_t i = 2; i < input.size(); i += 2) 
    {
        std::cout << "d" << g_depht << ": " << "Insert: " << input.at(i)  << std::endl;
        sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), input.at(i)), input.at(i));
        std::cout << "d" << g_depht << ": " << "Sorted: " << sorted;
    }


    --g_depht;
    std::cout << std::endl;

}
// 5 7 78 94
5  0  5  2  1
(0  1 )  (2  3 )
(1  0 )  (3  2 )
//  2 2 6 10 22
// 
// (y4, y3) (y6, y5) (y16, y15, y14, y13, y12, y11, y10, y9, y8, y7), 