/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:18:18 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/13 10:55:14 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {std::clog << "Ice defcons " << std::endl;};

Ice::Ice(const Ice& src) : AMateria(src)
{
	std::clog << "Ice cpycons " << std::endl;
};

Ice&	Ice::operator=(const Ice& src) 
{
	if (this == &src)
		return (*this);
	this->AMateria::operator=(src);
	return (*this);
};

Ice::~Ice(void) {std::clog << "Ice dest " << std::endl;};


Ice::Ice(std::string const & type) : AMateria(type) {std::clog << "Ice typcons " << std::endl;};
	
AMateria*	Ice::clone(void) const 
{
	Ice*	p = new Ice();
	
	std::clog << "Ice clone " << std::endl;
	return (p);
};
	
void	Ice::use(ICharacter& target) 
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
};
	
