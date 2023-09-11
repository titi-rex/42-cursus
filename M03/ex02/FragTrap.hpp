/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:51:41 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 20:51:42 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAG_TRAP_H__
# define _FRAG_TRAP_H__
# include "ClapTrap.hpp"

class FragTrap :  public ClapTrap
{
	
	private	:

	public	:

		FragTrap(void);
		FragTrap(const FragTrap& cpy);
		FragTrap&	operator=(const FragTrap& cpy);
		~FragTrap(void);

		FragTrap(const std::string name);

		void	highFiveGuys(void);
};

#endif
