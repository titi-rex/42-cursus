/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:58:04 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/13 22:23:43 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_H__
# define _ZOMBIE_H__
# include <string>

class Zombie
{
	private	:
		std::string	_name;
	
	public	:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		
		void	setName(std::string name);

};

#endif