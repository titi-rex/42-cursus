/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:09:55 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/28 14:53:27 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_H__
# define _DOG_H__
# include "Animal.hpp"
# include "Brain.hpp"
# include <string>
# include <iostream>

class Dog : public Animal
{
	private:
		Brain*	_brain;

	public	:
		Dog(void);
		Dog(const Dog& src);
		Dog&	operator=(const Dog& src);
		~Dog(void);

		Brain*	getBrain(void) const;

		void	makeSound(void) const;
};

#endif
