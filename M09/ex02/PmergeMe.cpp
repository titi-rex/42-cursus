/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:31:18 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/31 14:46:48 by tlegrand         ###   ########.fr       */
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


size_t PmergeMe::_getNextJacobstahl(int first, bool reset)
{
    static size_t  n2 = 0;
    static size_t  n1 = 2;
    size_t         n0 = 0;

    if (reset == true)
    {
        n2 = 0; 
        n1 = 2; 
    }
    else if (first == 0)
        n0 = 2;
    else
    {
        n0 = n1 + n2 * 2;
        n2 = n1;
        n1 = n0;
    }
    return (n0);
};

