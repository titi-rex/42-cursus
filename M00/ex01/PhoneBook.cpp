/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:32:55 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/13 21:58:51 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _idx(-1), _ncontact(0) {}


void	PhoneBook::_display_field(std::string str) const 
{
	
	std::string	tmp(str, 0, 10);

	if (str.size() > 10)
		tmp[9] = '.';
	std::cout << std::setw(10) << tmp;
}

void	PhoneBook::_display(void) const
{
	std::string	str;
	int			i = 0;

	std::cout << std::setw(10) << "INDEX" << "|" << std::setw(10) << "FIRST NAME" << "|" << std::setw(10) << "LAST NAME" << "|" << std::setw(10) << "NICKNAME" << std::endl;
	while (i < this->_ncontact)
	{
		std::cout << std::setw(10) << i << "|";
		str = this->_contact[i].getFname();
		this->_display_field(str);
		std::cout << "|";
		str = this->_contact[i].getLname();
		this->_display_field(str);
		std::cout << "|";
		str = this->_contact[i].getNname();
		this->_display_field(str);
		std::cout <<  std::endl;
		++i;
	}
}

void	PhoneBook::add_contact(std::string data[5]) 
{
	this->_idx = ++this->_idx % MAX_CONTACT;
	if (this->_ncontact < MAX_CONTACT)
		++this->_ncontact;
	this->_contact[this->_idx].fillContact(data[0], data[1], data[2], data[3], data[4]);
	std::cout << "ADDED" << std::endl;
}

void	PhoneBook::search(void) const {
	std::string	input;
	int			idx;
	
	if (this->_ncontact == 0)
		return ;
	this->_display();
	std::cout << "ENTER INDEX : ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	idx = input[0] - 48;
	if (idx < 0 || idx > this->_ncontact - 1)
	{
		std::cout << "INDEX NONEXISTENT" << std::endl;
		return ;
	}
	this->_contact[idx].display();
}
