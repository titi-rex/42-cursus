/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:46:41 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/28 13:38:57 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHARACTER_H__
# define _CHARACTER_H__
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	
	private	:
		std::string	_name;
		AMateria*	_inventory[4];

	public	:
		Character(void);
		Character(const Character& src);
		Character&	operator=(const Character& src);
		~Character(void);

		Character(std::string name);
		
		std::string const &	getName(void) const;
		void		setName(std::string name);
		AMateria*	getInventory(int idx) const;

		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif
