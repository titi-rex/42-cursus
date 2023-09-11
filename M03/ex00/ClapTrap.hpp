/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:06:51 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 15:16:40 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAP_TRAP_H__
# define _CLAP_TRAP_H__
# include <string>

class ClapTrap {
	
	private	:
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_ad;

	public	:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& cpy);
		ClapTrap&	operator=(const ClapTrap& cpy);
		~ClapTrap(void);

		std::string	getName(void) const;
		void	setName(std::string name);
		int		getHp(void) const;
		void	setHp(int hp);
		int		getEp(void) const;
		void	setEp(int ep);
		int		getAd(void) const;
		void	setAd(int ad);


		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
