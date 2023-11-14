/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:16 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/14 19:01:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {};
Serializer::Serializer(const Serializer& src) {(void)src;};
Serializer&	Serializer::operator=(const Serializer& src) {return ((void)src, *this);};
Serializer::~Serializer(void) {};


uintptr_t	Serializer::serialize(Data* ptr) 
{
	return(reinterpret_cast<uintptr_t>(ptr));
};
	
Data*	Serializer::deserialize(uintptr_t raw) 
{
	return(reinterpret_cast<Data*>(raw));
};
	
