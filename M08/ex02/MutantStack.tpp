/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:01:47 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/20 14:24:00 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) {};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& src) : std::stack<T>(src)
{
	
};

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& src) 
{
	if (this == &src)
		return (*this);
	return (*this);
};

template <typename T>
MutantStack<T>::~MutantStack(void) {};


template <typename T> iterator	MutantStack<T>::begin(void) {};
template <typename T> iterator	MutantStack<T>::end(void) {};

template <typename T> const_iterator	MutantStack<T>::cbegin(void) {};
template <typename T> const_iterator	MutantStack<T>::cend(void) {};
