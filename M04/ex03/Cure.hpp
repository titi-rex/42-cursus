/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:17:36 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/12 22:20:35 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CURE_H__
# define _CURE_H__
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public	:

		Cure(void);
		Cure(const Cure& src);
		Cure&	operator=(const Cure& src);
		~Cure(void);
		
		Cure(std::string const & type);
		
		AMateria* 	clone(void) const;
		void		 use(ICharacter& target);

};

#endif
