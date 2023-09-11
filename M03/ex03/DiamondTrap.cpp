/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:38:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 21:40:14 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : _name("") 
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->setGuardStatus(false);
	this->ClapTrap::setName("_clap_name");
	this->setHp(this->FragTrap::getHp());
	this->setEp(this->ScavTrap::getEp());
	this->setAd(this->FragTrap::getAd());
};

DiamondTrap::DiamondTrap(const DiamondTrap& cpy) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Copys constructor called" << std::endl;
	this->setName(cpy.getName());
	this->ClapTrap::setName(cpy.getName() + "_clap_name");
	this->setHp(cpy.getHp());
	this->setEp(cpy.getEp());
	this->setAd(cpy.getAd());
	this->setGuardStatus(cpy.getGuardStatus());
	
};

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& cpy) 
{
	if (this == &cpy)
		return (*this);
	this->setName(cpy.getName());
	this->ClapTrap::setName(cpy.getName() + "_clap_name");
	this->setHp(cpy.getHp());
	this->setEp(cpy.getEp());
	this->setAd(cpy.getAd());
	this->setGuardStatus(cpy.getGuardStatus());

	return (*this);
};

DiamondTrap::~DiamondTrap(void) {std::cout << "DiamondTrap destructor called" << std::endl;};

DiamondTrap::DiamondTrap(const std::string name) 
{
	std::cout << "DiamondTrap Name constructor called" << std::endl;
	this->setGuardStatus(false);
	this->setName(name);
	this->ClapTrap::setName(name + "_clap_name");
	this->setHp(this->FragTrap::getHp());
	this->setEp(this->ScavTrap::getEp());
	this->setAd(this->FragTrap::getAd());

};

std::string	DiamondTrap::getName(void) const { return (this->_name); };
void	DiamondTrap::setName(std::string name) { this->_name = name; };


void	DiamondTrap::whoAmI(void) 
{
	std::cout << "DiamondTrap my name is " << this->getName() << " and my ClapTrap name is " << this->ClapTrap::getName() << std::endl;
};
	
