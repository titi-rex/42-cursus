/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:51:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 21:41:39 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) 
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->setHp(100);
	this->setEp(100);
	this->setAd(30);
};

FragTrap::FragTrap(const FragTrap& cpy) : ClapTrap()
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	this->setName(cpy.getName());
	this->setHp(cpy.getHp());
	this->setEp(cpy.getEp());
	this->setAd(cpy.getAd());
};

FragTrap&	FragTrap::operator=(const FragTrap& cpy) 
{
	if (this == &cpy)
		return (*this);
	this->setName(cpy.getName());
	this->setHp(cpy.getHp());
	this->setEp(cpy.getEp());
	this->setAd(cpy.getAd());
	return (*this);
};

FragTrap::~FragTrap(void) {std::cout << "FragTrap destructor called" << std::endl;};

FragTrap::FragTrap(const std::string name) 
{
	std::cout << "FragTrap Name constructor called" << std::endl;
	this->setName(name);
	this->setHp(100);
	this->setEp(100);
	this->setAd(30);
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
	
