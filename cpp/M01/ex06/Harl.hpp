/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:33:57 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/10 00:26:25 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_H__
# define __HARL_H__
# include <string>


class Harl {
	
	private	:
		typedef	void (Harl::*hptr) (void) const;
	
		void		_debug(void) const;
		void		_info(void) const;
		void		_warning(void) const;
		void		_error(void) const;

	public	:
		Harl(void);
		~Harl(void);

		void	complain(int start) const;
		void	filter(std::string level) const;

};

#endif
