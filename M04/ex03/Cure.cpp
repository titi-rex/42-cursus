/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:18:22 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/12 23:36:42 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {std::clog << "Cure defcons " << std::endl;};

Cure::Cure(const Cure& src) : AMateria(src)
{
	std::clog << "Cure cpycons " << std::endl;

};

Cure&	Cure::operator=(const Cure& src) 
{
	if (this == &src)
		return (*this);
	this->AMateria::operator=(src);
	return (*this);
};

Cure::~Cure(void) {std::clog << "Cure dest " << std::endl;};


Cure::Cure(std::string const & type) : AMateria(type) {std::clog << "Cure typcons " << std::endl;};

AMateria*	Cure::clone(void) const 
{
	std::clog << "Cure clone " << std::endl;
	return (new Cure());
};
	
void	Cure::use(ICharacter& target) 
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
};
	
