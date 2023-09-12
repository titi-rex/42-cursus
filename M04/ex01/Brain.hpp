/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:40:17 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/12 20:44:16 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BRAIN_H__
# define _BRAIN_H__
# include <string>
# include <iostream>

class Brain 
{
	
	private	:
		std::string	_ideas[100];

	public	:

		Brain(void);
		Brain(const Brain& src);
		Brain&	operator=(const Brain& src);
		~Brain(void);

		// std::string*	getIdeas(void) const;
		// void			setIdeas(std::string ideas[100]);

};

#endif
