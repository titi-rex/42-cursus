/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:38:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 23:34:07 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DIAMOND_TRAP_H__
# define _DIAMOND_TRAP_H__
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap :  public ScavTrap, public FragTrap
{
	private	:
		std::string	_name;

	public	:

		DiamondTrap(void);
		DiamondTrap(const DiamondTrap& cpy);
		DiamondTrap&	operator=(const DiamondTrap& cpy);
		~DiamondTrap(void);

		DiamondTrap(std::string name);

		std::string	getName(void) const;
		void	setName(std::string name);

		void	whoAmI(void);
		void	myStats(void) const;
};

#endif
