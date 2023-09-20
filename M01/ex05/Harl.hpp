/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:33:57 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/20 15:25:45 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_H__
# define __HARL_H__
# include <string>

class Harl {
	
	private	:
		typedef	void (Harl::*hptr) (void);
	
		void		_debug(void);
		void		_info(void);
		void		_warning(void);
		void		_error(void);

	public	:
		Harl(void);
		~Harl(void);

		void	complain(std::string level);

};

#endif
