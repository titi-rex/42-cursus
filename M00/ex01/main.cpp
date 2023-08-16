/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:41:15 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/16 23:50:04 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

bool	get_input(std::string name, std::string *input) {

	std::cout << name << " : ";
	std::getline(std::cin, *input);
	if (input->empty() || (input->find_first_not_of(' ') == std::string::npos))
	{
		std::cout << "NO EMPTY FIELD ALLOWED" << std::endl;
		return (true);
	}
	if (std::cin.eof())
		return (true);
	return (false);
}

void	add(PhoneBook *p) {
	std::string	input[5];

	if (get_input("FIRST NAME", &input[0]))
		return ;
	if (get_input("LAST NAME", &input[1]))
		return ;
	if (get_input("NICKNAME", &input[2]))
		return ;
	if (get_input("PHONE NUMBER", &input[3]))
		return ;
	if (get_input("DARKEST SECRET", &input[4]))
		return ;
	p->add_contact(input);
}

int	main(void)
{
	PhoneBook	p;
	std::string	input;
	
	std::cout << std::setfill(' ');
	while(1)
	{
		if (std::cin.eof())
			break ;
		std::cout << "COMMAND ME : ";
		std::getline(std::cin, input);
		if (input == "ADD")
			add(&p);
		else if (input == "SEARCH")
			p.search();
		else if (input == "EXIT")
			break ;
	}
	return (0);
}
