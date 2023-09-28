/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:00:14 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/28 13:27:42 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ICE_H__
# define _ICE_H__
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public	:

		Ice(void);
		Ice(const Ice& src);
		Ice&	operator=(const Ice& src);
		~Ice(void);

		Ice(std::string const & type);

		AMateria*		clone(void) const;
		void			use(ICharacter& target);
};

#endif
