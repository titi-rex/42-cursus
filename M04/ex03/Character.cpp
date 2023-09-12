/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:49:29 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/12 23:54:24 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("nameless") 
{
	for (int i=0; i<4; ++i)
		this->_inventory[i] = NULL;
	std::clog << "Character defcons " << std::endl;
};

Character::Character(const Character& src) 
{
	this->setName(src.getName());
	for (int i=0; i<4; ++i)
		delete this->getInventory(i);
	for (int i=0; i<4; ++i)
	{
		if (src.getInventory(i) != NULL)
			equip(src.getInventory(i)->clone());
		else
			this->_inventory[i] = NULL;
	}
	std::clog << "Character cpycons " << std::endl;
};

Character&	Character::operator=(const Character& src) 
{
	if (this == &src)
		return (*this);
	for (int i=0; i<4; ++i)
		delete this->getInventory(i);
	for (int i=0; i<4; ++i)
	{
		if (src.getInventory(i) != NULL)
			equip(src.getInventory(i)->clone());
		else
			this->_inventory[i] = NULL;
	}
	this->setName(src.getName());
	return (*this);
};

Character::~Character(void) 
{
	std::clog << "Character dest " << std::endl;
	for (int i=0; i<4; ++i)
		delete this->getInventory(i);
};

Character::Character(std::string name) : _name(name) 
{
	for (int i=0; i<4; ++i)
		this->_inventory[i] = NULL;
	std::clog << "Character namecons " << std::endl;
};


std::string const &	Character::getName(void) const { return (this->_name); };
void				Character::setName(std::string name) { this->_name = name; };
AMateria*	Character::getInventory(int idx) const {return (this->_inventory[idx]);};


	
void	Character::equip(AMateria* m) 
{
	for (int i=0; i<4; ++i)
	{
		if (this->_inventory[i] == NULL)
			this->_inventory[i] = m;
	}
};
	
void	Character::unequip(int idx) 
{
	if (this->_inventory[idx] != NULL)
		this->_inventory[idx] = NULL;
};
	
void	Character::use(int idx, ICharacter& target) 
{
	if (this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
};
	
