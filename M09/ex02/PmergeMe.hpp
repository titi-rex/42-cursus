/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:31:21 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/28 16:29:26 by tlegrand         ###   ########.fr       */
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
std::clock_t timer(T& obj, void f(T&))
{
    std::clock_t start = std::clock();
    f(obj);
    std::clock_t end = std::clock();
    return (end - start);
}

template <typename T>
std::ostream& operator<<(std::ostream &os, std::vector<T> m)
{
    for (typename std::vector<T>::const_iterator it = m.begin(); it != m.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return (os);
}

void    compute(std::vector<int>& vec);

#endif
