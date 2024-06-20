/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:49:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/21 19:10:00 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_H__
# define _WEAPON_H__
#include <string>

class Weapon
{
	private	:
	
		std::string	_type;

	public	:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		
		const std::string&	getType(void) const;
		void				setType(std::string type);
};

#endif