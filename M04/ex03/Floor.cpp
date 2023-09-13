/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:55:23 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/13 20:18:34 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

int Floor::_n_node = 0;

Floor::Floor(void) : _m(NULL), _next(NULL) {++this->_n_node; std::clog << "Floor defcons " << std::endl;};

Floor::Floor(const Floor& src) 
{
	*this = src;
	++this->_n_node;
	std::clog << "Floor cpycons " << std::endl;
};

Floor&	Floor::operator=(const Floor& src) 
{
	if (this == &src)
		return (*this);
	if (this->_m != NULL)
		delete this->_m;
	if (this->_next != NULL)
		delete this->_next;
	this->_m = src._m;
	this->_next = src._next;
	return (*this);
};

Floor::~Floor(void) 
{
	delete this->_m;
	delete this->_next;
	this->_next = NULL;
	std::clog << "Floor dest " << std::endl;
};

Floor::Floor(AMateria* m) : _m(m), _next(NULL) {++this->_n_node; std::clog << "Floor Matcons " << std::endl;};

int		Floor::getNNode(void) const {return (this->_n_node);};
void	Floor::setNNode(int n) {this->_n_node = n;};


void	Floor::addNode(AMateria* m) 
{
	Floor*	tmp = this;

	while (tmp->_next)
		tmp = tmp->_next;
	tmp->_next = new Floor(m);
	std::clog << "Node added " << std::endl;
};

