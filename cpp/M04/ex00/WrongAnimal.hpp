/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:57:19 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/12 18:57:28 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WRONG_ANIMAL_H__
# define _WRONG_ANIMAL_H__
# include <iostream>

class WrongAnimal 
{
	
	protected:
		std::string	_type;

	public	:

		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& src);
		WrongAnimal&	operator=(const WrongAnimal& src);
		~WrongAnimal(void);

		std::string	getType(void) const;
		void	setType(std::string type);

		void	makeSound(void) const;
};

#endif
