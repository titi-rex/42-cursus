/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:40:19 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/14 18:59:26 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SERIALIZER_H__
# define _SERIALIZER_H__
# include "Data.hpp"

class Serializer 
{
	private	:
		Serializer(void);
		Serializer(const Serializer& src);
		Serializer&	operator=(const Serializer& src);
		~Serializer(void);

	public	:
		static	uintptr_t	serialize(Data* ptr);
		static	Data*		deserialize(uintptr_t raw);
};

#endif
