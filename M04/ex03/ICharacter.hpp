/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:21:26 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/28 14:02:42 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _I_CHARACTER_H__
# define _I_CHARACTER_H__
# include <string>
# include "AMateria.hpp"

class AMateria;

class ICharacter 
{
	public	:
		virtual	~ICharacter(void) {};
		virtual std::string	const &	getName(void) const = 0;
		virtual void	equip(AMateria* m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;
};

#endif

