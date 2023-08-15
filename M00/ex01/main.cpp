/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:41:15 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/15 17:04:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int	main()
{
	PhoneBook	p1(13);
	PhoneBook	p2(13);
	PhoneBook	p3(9);
	Contact		c;
	
	int	PhoneBook::*p;
	
	p1.hello();
	std::cout << "compare p1 p2 " << p1.compare(&p2) << std::endl;
	std::cout << "compare p1 p3 " << p1.compare(&p3) << std::endl;
	return (0);
}
