/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:39:11 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/13 00:06:33 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _A_MATERIA_H__
# define _A_MATERIA_H__
# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria 
{
	
	protected:
		std::string	_type;

	public	:

		AMateria(void);
		AMateria(const AMateria& src);
		AMateria&	operator=(const AMateria& src);
		virtual ~AMateria(void);

		AMateria(std::string const& type);

		std::string	getType(void) const;
		void		setType(std::string type);
		
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);
};

#endif
