/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:04:21 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/05 22:07:23 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BASE_H__
# define _BASE_H__

class Base
{
	public	:
		virtual ~Base() {};	
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
