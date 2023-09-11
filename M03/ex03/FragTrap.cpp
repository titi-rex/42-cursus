/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:51:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 22:50:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) 
{
	this->setHp(100);
	this->setEp(100);
	this->setAd(30);
	std::cout << "FragTrap Default constructor called" << std::endl;
};

FragTrap::FragTrap(const FragTrap& cpy) : ClapTrap(cpy)
{
	std::cout << "FragTrap ("<< this->getName() << ") Copy constructor called" << std::endl;
};

FragTrap&	FragTrap::operator=(const FragTrap& cpy) 
{
	if (this == &cpy)
		return (*this);
	this->ClapTrap::operator=(cpy);
	return (*this);
};

FragTrap::~FragTrap(void) {std::cout << "FragTrap ("<< this->getName() << ") Destructor called" << std::endl;};

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->setHp(100);
	this->setEp(100);
	this->setAd(30);
	std::cout << "FragTrap ("<< this->getName() << ") Name constructor called" << std::endl;
};

void	FragTrap::highFiveGuys(void) 
{
	if (this->getHp() <= 0)
	{
		std::cout << "FragTrap " << this->getName() << " is dead... Can't highfive you anymore.." << std::endl;
		return ;
	}
	std::cout << "Fragtrap " << this->getName() << " want a highfive !" << std::endl;
};
	
