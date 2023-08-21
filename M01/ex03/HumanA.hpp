/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:49:57 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/21 19:42:30 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMAN_A_H__
# define _HUMAN_A_H__
# include "Weapon.hpp"
# include <string>

class HumanA
{
	private	:
		std::string	_name;
		Weapon&		_weapon;

	public	:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
		void	attack(void) const;
};

#endif