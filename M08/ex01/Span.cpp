/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:31:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/19 19:54:13 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _stock(), _max_size(0) {};

Span::Span(const Span& src) : _max_size(src._max_size)
{
	_stock = src._stock;
};

Span&	Span::operator=(const Span& src) 
{
	if (this == &src)
		return (*this);
	_stock = src._stock;
	return (*this);
};

Span::~Span(void) {};

Span::Span(unsigned int n) : _max_size(n)
{
	_stock.reserve(n);
};

void	Span::addNumber(int n) 
{
	if (_stock.size() > _max_size)
		throw std::invalid_argument("No more place left!");
	_stock.push_back(n);
};
	
	
int	Span::shortestSpan(void) const
{
	if (_stock.size() <= 1)
		throw std::runtime_error("Not enought number stored");

	int	res = -1;
	std::vector<int>	tmp_stock = _stock;
	std::sort(tmp_stock.begin(), tmp_stock.end());
	int	tmp = tmp_stock[0];
	for (std::vector<int>::const_iterator it = tmp_stock.begin() + 1; it != tmp_stock.end(); ++it)
	{
		if (std::abs(*it - tmp) <= res || res == -1)
			res = std::abs(*it - tmp);
		tmp = *it;
	}
	return (res);
};
	
int	Span::longestSpan(void) const
{
	if (_stock.size() <= 1)
		throw std::runtime_error("Not enought number stored");

	int min = *std::min_element(_stock.begin(), _stock.end());
	int max = *std::max_element(_stock.begin(), _stock.end());
	return (max - min);
};
	
void	Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end) 
{
	if (std::distance(start, end) + _stock.size() > _max_size)
		throw std::invalid_argument("No more place left!");
	for (std::vector<int>::iterator it = start; it != end; ++it)
	{
		_stock.push_back(*it);
	}
};
	
