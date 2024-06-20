/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:49:57 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/18 21:45:06 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMAN_B_H__
# define _HUMAN_B_H__
# include "Weapon.hpp"
# include <string>

class HumanB
{
	private	:
		std::string	_name;
		Weapon*		_weapon;

	public	:
		HumanB(std::string name);
		~HumanB(void);
		void	attack(void) const;
		void	setWeapon(Weapon* weapon);
};

#endif