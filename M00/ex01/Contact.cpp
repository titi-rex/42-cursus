/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:47:01 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/15 13:49:20 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Constructor C" << std::endl;
	return ;
}

Contact::~Contact(void) {
	std::cout << "Destructor C" << std::endl;
	return ;
}
