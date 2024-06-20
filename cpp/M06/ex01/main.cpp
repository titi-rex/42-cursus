/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:39:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/14 19:03:21 by tlegrand         ###   ########.fr       */
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
	int			t = 5;
	
	
	data.id = 19;
	data.name = "my name is jhone";
	data.ptr = &t;
	raw = Serializer::serialize(&data);
	d_ptr = Serializer::deserialize(raw);
	std::cout << "Data & "<< &data << std::endl << "Deserialze & "<< d_ptr <<  std::endl;
	if (&data != Serializer::deserialize(Serializer::serialize(&data)))
		std::cout << "Error !" << std::endl;
	else
		std::cout << "Same address !" << std::endl;
	std::cout << "data id : " << d_ptr->id << ", name : " << d_ptr->name << ", value of addr : " << *(int*)(d_ptr->ptr) << std::endl; 
}
