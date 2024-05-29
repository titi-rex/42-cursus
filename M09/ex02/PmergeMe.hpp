/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:31:21 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/29 13:55:16 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __RPN__
# define __RPN__
# include <vector>
# include <deque>

# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <ctime>
# include <algorithm>

# include <exception>
#include <unistd.h> 

template <typename T>
std::clock_t timer(T& obj1, T& obj2, void f(T&, T&))
{
    std::clock_t start = std::clock();
    f(obj1, obj2);
    std::clock_t end = std::clock();
    return (end - start);
}

template <typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T>& m)
{
    for (typename std::vector<T>::const_iterator it = m.begin(); it != m.end(); ++it)
    {
        os << *it << " ";
    }
    os << std::endl;
    return (os);
}

template <typename T> void swap(T& a, T& b)
{
	T	tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T> const T& min(const T& a, const T& b)
{
	return ((a < b) ? a : b);
}

template <typename T> const T& max(const T& a, const T& b)
{
	return ((a > b) ? a : b);
}


void    compute(std::vector<int>& vec, std::vector<int>& sorted);

#endif
