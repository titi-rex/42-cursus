/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:13:18 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 22:48:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : _guardStatus(false)
{
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
	std::cout << "ScavTrap Default constructor called" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap& cpy) : ClapTrap(cpy)
{
	this->setGuardStatus(cpy.getGuardStatus());
	std::cout << "ScavTrap ("<< this->getName() << ") Copy constructor called" << std::endl;
};

ScavTrap&	ScavTrap::operator=(const ScavTrap& cpy) 
{
	if (this == &cpy)
		return (*this);
	this->ClapTrap::operator=(cpy);
	this->setGuardStatus(cpy.getGuardStatus());
	return (*this);
};

ScavTrap::~ScavTrap(void) {std::cout << "ScavTrap ("<< this->getName() << ") Destructor called" << std::endl;};

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name), _guardStatus(false)
{
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
	std::cout << "ScavTrap ("<< this->getName() << ") Name constructor called" << std::endl;
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
	
