/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:32:55 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/15 16:18:00 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

// PhoneBook::PhoneBook(int val) {
// 	std::cout << "Constructor PB" << std::endl;
// 	this->e = val;
// 	return ;
// }

PhoneBook::PhoneBook(int const val) : _privint(val) {
	std::cout << "Constructor PB" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "Destructor PB" << std::endl;
	return ;
}

void	PhoneBook::hello(void) const {
	std::cout << "Hello e " << this->_privint << std::endl;
}

void	PhoneBook::setPrivint(int const val) {
	if (val >= 0)
		this->_privint = val;
	return ;
}

int	PhoneBook::getPrivint(void) const {
	return (this->_privint);
}

int	PhoneBook::compare(PhoneBook *other) const {
	if (this->_privint != other->getPrivint())
		return (1);
	return (0);
}