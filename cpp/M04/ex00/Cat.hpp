/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:07:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/28 13:20:43 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_H__
# define _CAT_H__
# include "Animal.hpp"
# include <string>
# include <iostream>

class Cat : public Animal
{
	public	:

		Cat(void);
		Cat(const Cat& src);
		Cat&	operator=(const Cat& src);
		~Cat(void);

		void	makeSound(void) const;
};

#endif
