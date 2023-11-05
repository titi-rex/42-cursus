/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:39:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/05 22:01:23 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		data;
	Data*		d_ptr;
	uintptr_t	raw;
	
	raw = Serializer::serialize(&data);
	d_ptr = Serializer::deserialize(raw);
	std::cout << "Data & "<< &data << std::endl << "Deserialze & "<< d_ptr <<  std::endl;

	if (&data != Serializer::deserialize(Serializer::serialize(&data)))
		std::cout << "Error !" << std::endl;
	else
		std::cout << "Same address !" << std::endl;
}
