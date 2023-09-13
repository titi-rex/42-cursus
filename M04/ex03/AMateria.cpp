/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:41:28 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/13 20:18:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

Floor* AMateria::_floor = NULL;

AMateria::AMateria(void) : _type("none") {std::clog << "AMateria defcons " << std::endl;};

AMateria::AMateria(const AMateria& src) : _type(src.getType()) {std::clog << "AMateria cpycons " << std::endl;};

AMateria&	AMateria::operator=(const AMateria& src) 
{
	if (this == &src)
		return (*this);
	this->setType(src.getType());
	return (*this);
};

AMateria::~AMateria(void) 
{
	std::clog << "AMateria dest " << std::endl;
};

AMateria::AMateria(std::string const& type) : _type(type) {std::clog << "AMateria typcons " << std::endl;};


std::string	AMateria::getType(void) const { return (this->_type); };
void		AMateria::setType(std::string type) {this->_type = type;};

Floor*	AMateria::getFloor(void) const { return (this->_floor); };


void AMateria::use(ICharacter& target) 
{
	std::cout << "* nothing happend to " << target.getName() << " *" << std::endl;
};


void	AMateria::addNode(void) 
{
	if (this->_floor == NULL)
		this->_floor = new Floor(this);
	else
		this->_floor->addNode(this);
};

void	AMateria::clearFloor(void)
{
	delete this->_floor;
	this->_floor = NULL;
	std::clog << "Cleanning floor : " << this->_floor->getNNode() << " object cleared" << std::endl;
	this->_floor->setNNode(0);
};


