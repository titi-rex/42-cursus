/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:58:04 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/19 17:10:47 by tlegrand         ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);

};

#endif