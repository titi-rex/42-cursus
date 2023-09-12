/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:41:28 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/13 00:21:28 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("none") {std::clog << "AMateria defcons " << std::endl;};

AMateria::AMateria(const AMateria& src) : _type(src.getType()) {std::clog << "AMateria cpycons " << std::endl;};

AMateria&	AMateria::operator=(const AMateria& src) 
{
	if (this == &src)
		return (*this);
	this->setType(src.getType());
	return (*this);
};

AMateria::~AMateria(void) {std::clog << "AMateria dest " << std::endl;};

AMateria::AMateria(std::string const& type) : _type(type) {std::clog << "AMateria typcons " << std::endl;};

std::string	AMateria::getType(void) const { return (this->_type); };
void		AMateria::setType(std::string type) {this->_type = type;};

	

void AMateria::use(ICharacter& target) 
{
	std::cout << "* nothing happend at " << target.getName() << " *" << std::endl;
};
	
