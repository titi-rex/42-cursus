/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:07:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/28 13:21:01 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WRONG_CAT_H__
# define _WRONG_CAT_H__
# include "WrongAnimal.hpp"
# include <string>
# include <iostream>

class WrongCat : public WrongAnimal
{
	public	:

		WrongCat(void);
		WrongCat(const WrongCat& src);
		WrongCat&	operator=(const WrongCat& src);
		~WrongCat(void);

		void	makeSound(void) const;
};

#endif
