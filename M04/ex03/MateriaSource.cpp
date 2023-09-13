/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:08:57 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/13 11:34:36 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) 
{
	for (int i=0; i<4; ++i)
		this->_stock[i] = NULL;
	std::clog << "MateriaSource defcons " << std::endl;
};

MateriaSource::MateriaSource(const MateriaSource& src) 
{
	for (int i=0; i<4; ++i)
		delete this->_stock[i];
	for (int i=0; i<4; ++i)
	{
		if (src._stock[i] != NULL)
			learnMateria(src._stock[i]);
		else
			this->_stock[i] = NULL;
	}
	std::clog << "MateriaSource cpycons " << std::endl;
};

MateriaSource&	MateriaSource::operator=(const MateriaSource& src) 
{
	if (this == &src)
		return (*this);
	for (int i=0; i<4; ++i)
		delete this->_stock[i];
	for (int i=0; i<4; ++i)
	{
		if (src._stock[i] != NULL)
			learnMateria(src._stock[i]);
		else
			this->_stock[i] = NULL;
	}
	return (*this);
};

MateriaSource::~MateriaSource(void) 
{
	std::clog << "MateriaSource dest " << std::endl;
	for (int i=0; i<4; ++i)
		delete this->_stock[i];
};

AMateria*	MateriaSource::getStock(int idx) const {return (this->_stock[idx]);};


void	MateriaSource::learnMateria(AMateria* m) 
{
	for (int i=0; i<4; ++i)
	{
		if (this->_stock[i] == NULL)
		{
			this->_stock[i] = m;	// pas une deep copy !!! utilisr clone mais le main leak?
			return ;				// dlete me sinon apprise ??
		}
	}
};
	
AMateria*	MateriaSource::createMateria(std::string const & type) 
{
	for (int i=0; i<4; ++i)
	{
		if (this->_stock[i] != NULL && (this->_stock[i]->getType() == type))
			return (this->_stock[i]->clone());
	}
	return (NULL);
};
	
