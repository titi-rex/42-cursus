/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:13:16 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 17:10:27 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAV_TRAP_H__
# define _SCAV_TRAP_H__
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	// je t'aime <3 
	private	:
		bool	_guardStatus;
		
	public	:

		ScavTrap(void);
		ScavTrap(const ScavTrap& cpy);
		ScavTrap&	operator=(const ScavTrap& cpy);
		~ScavTrap(void);

		ScavTrap(const std::string name);

		bool	getGuardStatus(void) const;
		void	setGuardStatus(bool status);

		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif
