/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:19:23 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/15 22:12:27 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARRAY_T__
# define _ARRAY_T__

template <typename T> Array<T>::Array(void)
{
	this->_arr = new T[0];
	this->_size = 0;
}

template <typename T> Array<T>::Array(unsigned int n)
{
	this->_arr = new T[n];
	this->_size = n;
}

template <typename T> Array<T>::Array(const Array<T>& src)
{
	this->_size = src._size;
	this->_arr = new T[this->_size];
	for (size_t i = 0; i < this->_size; ++i)
		this->_arr[i] = src._arr[i];
}

template <typename T> Array<T>& Array<T>::operator=(const Array<T>& src)
{
	if (this == &src)
		return (*this);
	delete[] this->_arr;
	this->_size = src._size;
	this->_arr = new T[this->_size];
	for (size_t i = 0; i < this->_size; ++i)
		this->_arr[i] = src._arr[i];
	return (*this);
}

template <typename T> Array<T>::~Array(void)
{
	this->_size = 0;
	delete[] this->_arr;
}

template <typename T> T& Array<T>::operator[](const int i) const
{
	if (i < 0 || i >= static_cast<int>(this->_size))
		throw std::exception();
	return (this->_arr[i]);
}

template <typename T> size_t Array<T>::size(void) const {return(this->_size);}

#endif
