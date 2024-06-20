/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:38:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 23:34:48 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// OCF
DiamondTrap::DiamondTrap(void) : _name("nameless") 
{
	this->ClapTrap::setName("nameless_clap_name");
	this->setEp(50);
	std::cout << "DiamondTrap Default constructor called" << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	this->setName(src.getName());
	std::cout << "DiamondTrap ("<< this->getName() << ") Copy constructor called" << std::endl;
};

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& cpy) 
{
	if (this == &cpy)
		return (*this);
	this->ScavTrap::operator=(cpy);
	this->setName(cpy.getName());
	return (*this);
};

DiamondTrap::~DiamondTrap(void) {std::cout << "DiamondTrap ("<< this->getName() << ") Destructor called" << std::endl;};

// others constructor
DiamondTrap::DiamondTrap(const std::string name) 
{
	this->setName(name);
	this->ClapTrap::setName(name + "_clap_name");
	this->setEp(50);
	std::cout << "DiamondTrap ("<< this->getName() << ") Name constructor called" << std::endl;
};


// get/set
std::string	DiamondTrap::getName(void) const { return (this->_name); };
void	DiamondTrap::setName(std::string name) { this->_name = name; this->ClapTrap::setName(name + "_clap_name");};

// public func
void	DiamondTrap::whoAmI(void) 
{
	std::cout << "DiamondTrap my name is " << this->getName() << " and my ClapTrap name is " << this->ClapTrap::getName() << std::endl;
};
	
void	DiamondTrap::myStats(void) const
{
	std::cout << "My healt : " << this->getHp() << ", my stamina : " << this->getEp() << ", my strenght : " << this->getAd() << ", my guarding status : " << this->getGuardStatus() << std::endl;	
};
