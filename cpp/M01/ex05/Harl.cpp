/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:34:03 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/20 15:25:42 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) {std::cout << "Harl constructor called" << std::endl;};

Harl::~Harl(void) {std::cout << "Harl destructor called" << std::endl;};


void	Harl::_debug(void) {std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;};
	
void	Harl::_info(void) {std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;};
	
void	Harl::_warning(void) {std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;};
	
void	Harl::_error(void) {std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl; };
	
void	Harl::complain(std::string level) 
{
	std::string	str[4] = {"DEBUG", "INFO","WARNING", "ERROR"};
	hptr		func[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (int i=0; i < 4; ++i)
	{
		if (level.compare(str[i]) == 0)
		{
			(this->*func[i])();
			break ;
		}
	}
};
