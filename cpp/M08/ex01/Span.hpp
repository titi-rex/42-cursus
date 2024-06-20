/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:21:54 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/25 12:19:57 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SPAN_H__
# define _SPAN_H__
# include <stdexcept>
# include <vector>
# include <algorithm>
# include <utility>

class Span 
{
	
	private	:
		std::vector<int>	_stock;
		size_t				_max_size;

		Span(void);
	public	:
		Span(const Span& src);
		Span&	operator=(const Span& src);
		~Span(void);

		Span(unsigned int n);

		void addNumber(int n);
		void addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
		int	shortestSpan(void) const;
		int	longestSpan(void) const;
};

#endif
