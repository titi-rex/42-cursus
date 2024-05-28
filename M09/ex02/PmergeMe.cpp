/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:31:18 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/28 16:30:55 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    display(std::string str)
{
    std::cout << str << std::endl;
}


bool tri(const int& a,const int& b){return a<b;}

void    compute(std::vector<int>& vec)
{
    if (vec.size() == 1)
        return ;
    
    std::vector<int>    tmp;

    for (std::vector<int>::const_iterator it = vec.begin(); it < vec.end(); it += 2)
    {
        if (it + 1 == vec.end())
            break ;
        if (*it > *(it + 1))
            tmp.push_back(*it);
        else
            tmp.push_back(*(it + 1));
    }
    std::cout << tmp;
    std::sort(tmp.begin(),tmp.end(), tri);
    std::cout << tmp;
    // compute(tmp);
}


