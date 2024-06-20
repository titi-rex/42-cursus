/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:06:49 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 23:18:58 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("nameless"), _hp(10), _ep(10), _ad(0) {std::cout << "ClapTrap Default constructor called" << std::endl;};

ClapTrap::ClapTrap(const std::string name) : _hp(10), _ep(10), _ad(0) 
{
	this->setName(name);
	std::cout << "ClapTrap ("<< this->getName() << ") Name constructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& cpy)
{
	this->setName(cpy.getName());
	this->setHp(cpy.getHp());
	this->setEp(cpy.getEp());
	this->setAd(cpy.getAd());
	std::cout << "ClapTrap ("<< this->getName() << ") Copy constructor called" << std::endl;
};

ClapTrap&	ClapTrap::operator=(const ClapTrap& cpy) 
{
	if (this == &cpy)
		return (*this);
	this->setName(cpy.getName());
	this->setHp(cpy.getHp());
	this->setEp(cpy.getEp());
	this->setAd(cpy.getAd());
	return (*this);
};

ClapTrap::~ClapTrap(void) {std::cout << "ClapTrap ("<< this->getName() << ") Destructor called" << std::endl;};

std::string	ClapTrap::getName(void) const { return (this->_name); };
void	ClapTrap::setName(std::string name) { this->_name = name; };

int	ClapTrap::getHp(void) const { return (this->_hp); };
void	ClapTrap::setHp(int hp) { this->_hp = hp; };

int	ClapTrap::getEp(void) const { return (this->_ep); };
void	ClapTrap::setEp(int ep) { this->_ep = ep; };

int	ClapTrap::getAd(void) const { return (this->_ad); };
void	ClapTrap::setAd(int ad) { this->_ad = ad; };


void	ClapTrap::attack(const std::string& target) 
{
	if (this->getHp() <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is dead..." << std::endl;
		return ;
	}
	if (this->getEp() <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " has no energy left ..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAd() << " points of damage !" << std::endl;
	this->setEp(this->getEp() - 1);
};

void	ClapTrap::takeDamage(unsigned int amount) 
{
	if (this->getHp() <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is already dead..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " has taken " << amount << " damage !" << std::endl;
	this->setHp(this->getHp() - amount);
	if (this->getHp() <= 0)
		std::cout << "ClapTrap " << this->getName() << " has fallen amid the brave..." << std::endl;
};

void	ClapTrap::beRepaired(unsigned int amount) 
{
	if (this->getHp() <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is dead..." << std::endl;
		return ;
	}
	if (this->getEp() <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " has no energy left ..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " repaired itself and heal " << amount << " hit points." << std::endl;
	this->setHp(this->getHp() + amount);
	this->setEp(this->getEp() - 1);
};
	
