/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:07:21 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/28 14:38:55 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANIMAL_H__
# define _ANIMAL_H__
# include <string>
# include <iostream>

class Animal 
{
	
	protected:
		std::string	_type;

	public	:

		Animal(void);
		Animal(const Animal& src);
		Animal&	operator=(const Animal& src);
		virtual ~Animal(void);

		std::string	getType(void) const;
		void		setType(std::string type);

		virtual void	makeSound(void) const = 0;
};

#endif
