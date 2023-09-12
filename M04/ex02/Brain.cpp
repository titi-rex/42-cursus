/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:40:15 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/12 20:49:25 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) 
{
	for (int i=0; i<100; ++i)
		this->_ideas[i] = "empty tought";
	std::cout << "Brain default constructor" << std::endl;
};

Brain::Brain(const Brain& src) 
{
	for (int i=0; i<100; ++i)
		this->_ideas[i] = src._ideas[i];
	std::cout << "Brain copy constructor" << std::endl;
};

Brain&	Brain::operator=(const Brain& src) 
{
	if (this == &src)
		return (*this);
	for (int i=0; i<100; ++i)
		this->_ideas[i] = src._ideas[i];
	return (*this);
};

	
Brain::~Brain(void) {std::cout << "Brain destructor" << std::endl;};

// std::string&	Brain::getIdeas(void) const { return (&this->_ideas); };
// void	Brain::setIdeas(std::string ideas[100]) { this->_ideas = ideas; };


