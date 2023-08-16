/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:47:01 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/17 00:13:02 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact(void) : _fname(""), _lname(""), _nname(""), _pnumber(""), _secret("") {}

std::string	Contact::getFname(void) const {
	return (this->_fname);
}

std::string	Contact::getLname(void) const {
	return (this->_lname);
}

std::string	Contact::getNname(void) const {
	return (this->_nname);
}

std::string	Contact::getPnumber(void) const {
	return (this->_pnumber);
}

std::string	Contact::getSecret(void) const {
	return (this->_secret);
}

void	Contact::display(void) const {
	std::cout << std::setw(14) << "FIRST NAME : " << this->_fname << std::endl;
	std::cout << std::setw(14) << "LAST NAME : " << this->_lname << std::endl;
	std::cout << std::setw(14) << "NICKNAME : " << this->_nname << std::endl;
	std::cout << std::setw(14) << "NUMBER : " << this->_pnumber << std::endl;
	std::cout << std::setw(14) << "SECRET : " << this->_secret << std::endl;
}

void	Contact::fillContact(std::string fname, std::string lname, std::string pnumber, std::string nname, std::string secret) {
	this->_fname = fname;
	this->_lname = lname;
	this->_nname = nname;
	this->_pnumber = pnumber;
	this->_secret = secret;
	return ;
}

