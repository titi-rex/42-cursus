/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:56:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/28 14:02:19 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _I_MATERIA_SOURCE_H__
# define _I_MATERIA_SOURCE_H__
# include <string>
# include <iostream>
# include "AMateria.hpp"

class AMateria;

class IMateriaSource 
{
	public	:
		virtual 			~IMateriaSource(void) {};
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif
