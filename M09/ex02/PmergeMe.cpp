/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:31:18 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/29 21:22:50 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _verbose(false), _depht(0), _dVerbosity(0) {};
PmergeMe::~PmergeMe(void) {};
PmergeMe::PmergeMe(const PmergeMe& src){*this = src;};
PmergeMe& PmergeMe::operator=(const PmergeMe& src) 
{
    if (&src == this)
        return (*this);
    _verbose = src._verbose;
    _depht = src._depht;
    return (*this);
};

PmergeMe::PmergeMe(bool verbose, int depth_verbosity) : _verbose(verbose), _depht(0), _dVerbosity(depth_verbosity) {};


void    PmergeMe::_dive(void) 
{
    ++_depht;
    if (_verbose && _depht >= _dVerbosity)
        std::cout << std::endl;
};

void    PmergeMe::_rise(void)
{
    --_depht;
    if (_verbose && _depht >= _dVerbosity)
        std::cout << std::endl;
};



size_t g_depht = 0;

int&    sortIntByMax(int& a, int& b)
{
    if (a > b)
        swap(a, b);
    return (b);    
}

void    computer(std::vector<int>& input, std::vector<int>& sorted)
{
    std::vector<int>    seq;
    int                 odd = -1;

    std::cout << std::endl;
    if (++g_depht >= 7)
        exit(1);

    // pop last if odd 
    if (input.size() % 2 == 1)
    {
        odd = input.back();
        std::cout << "d" << g_depht << ": " << "Alone: " << odd << std::endl;
        input.pop_back();
    }


    if (input.size() > 2)
    {
        // for each pair: sortIntByMax inside by max and extract max to s
        for (size_t i = 0; i < input.size(); i += 2) 
        {
            seq.push_back(sortIntByMax(input.at(i), input.at(i + 1)));
        }
        std::cout << "d" << g_depht << ": " << "Input: (size: " << input.size() << ") " << input;
        std::cout << "d" << g_depht << ": " << "Sequence: " << seq;
        computer(seq, sorted);
    }
    else
    {
        std::cout << "d" << g_depht << ": " << "MAX DEPTH REACHED" << std::endl;
        sorted = input;
        sortIntByMax(sorted.at(0), sorted.at(1));
        std::cout << "d" << g_depht << ": " << "Input: " << input;
        std::cout << "d" << g_depht << ": " << "Sorted: " << sorted;
        if (odd != -1)
        {
            std::cout << "d" << g_depht << ": " << "Insert alone: " << odd  << std::endl;
            sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), odd), odd);
            std::cout << "d" << g_depht << ": " << "Sorted: " << sorted;
        }

        std::cout << std::endl;
        --g_depht;
        return ;
    }
    std::cout << "d" << g_depht << ": " << "Input: " << input;
    std::cout << "d" << g_depht << ": " << "Sorted: " << sorted;

    // sortIntByMax all pair by max element based on sorted
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

    // if (odd != -1)
    //     input.push_back(odd);
    // inject in sorted
    sorted.insert(sorted.begin(), input.at(0));
    std::cout << "d" << g_depht << ": " << "Insert first: " << input.at(0)  << std::endl;
    std::cout << "d" << g_depht << ": " << "Sorted: " << sorted;
    for (size_t i = 2; i < input.size(); i += 2) 
    {
        std::cout << "d" << g_depht << ": " << "Insert: " << input.at(i)  << std::endl;
        sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), input.at(i)), input.at(i));
        std::cout << "d" << g_depht << ": " << "Sorted: " << sorted;
    }
    if (odd != -1)
    {
        std::cout << "d" << g_depht << ": " << "Insert alone: " << odd  << std::endl;
        sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), odd), odd);
        std::cout << "d" << g_depht << ": " << "Sorted: " << sorted;
    }

    --g_depht;
    std::cout << std::endl;

}
