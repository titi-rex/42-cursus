/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:59:40 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/15 22:04:32 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARRAY_H__
# define _ARRAY_H__
# include <exception>

template <typename T> class Array
{
	private	:
		T		*_arr;
		size_t	_size;

	public	:
		Array(void);
		Array(const Array<T>& src);
		Array(unsigned int n);
		~Array(void);

		Array<T>& operator=(const Array<T>& src);
		T& operator[](const int i) const;
		size_t	size(void) const;
};

template <typename T> void	print_arr(Array<T>& arr)
{
	for (size_t i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;	
}

# include "Array.tpp"

#endif
