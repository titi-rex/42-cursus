/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:13:18 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 21:41:25 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : _guardStatus(false)
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
};

ScavTrap::ScavTrap(const ScavTrap& cpy) : ClapTrap()
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	this->setGuardStatus(cpy.getGuardStatus());
	this->setName(cpy.getName());
	this->setHp(cpy.getHp());
	this->setEp(cpy.getEp());
	this->setAd(cpy.getAd());
};

ScavTrap&	ScavTrap::operator=(const ScavTrap& cpy) 
{
	if (this == &cpy)
		return (*this);
	this->setGuardStatus(cpy.getGuardStatus());
	this->setName(cpy.getName());
	this->setHp(cpy.getHp());
	this->setEp(cpy.getEp());
	this->setAd(cpy.getAd());
	return (*this);
};

ScavTrap::~ScavTrap(void) {std::cout << "ScavTrap destructor called" << std::endl;};

ScavTrap::ScavTrap(const std::string name) : _guardStatus(false)
{
	std::cout << "ScavTrap Name constructor called" << std::endl;
	this->setName(name);
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
};

bool	ScavTrap::getGuardStatus(void) const { return (this->_guardStatus); };
void	ScavTrap::setGuardStatus(bool status) { this->_guardStatus = status; };


void	ScavTrap::attack(const std::string& target) 
{
	if (this->getHp() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is dead..." << std::endl;
		return ;
	}
	if (this->getEp() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " need to sleep ..." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " violently attacks " << target << ", causing " << this->getAd() << " points of damage !" << std::endl;
	this->setEp(this->getEp() - 1);
};

void	ScavTrap::guardGate(void) 
{
	if (this->getHp() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is dead..." << std::endl;
		return ;
	}
	if (this->getGuardStatus() == false)
	{
		std::cout << "ScavTrap " << this->getName() << " is now guarding the gate!" << std::endl;
		this->setGuardStatus(true);
	}
	std::cout << "ScavTrap " << this->getName() << " is already guarding the gate..." << std::endl;
};
	
