/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:08:47 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/28 14:04:21 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MATERIA_SOURCE_H__
# define _MATERIA_SOURCE_H__
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	
	private	:
		AMateria*	_stock[4];

	public	:
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		MateriaSource&	operator=(const MateriaSource& src);
		~MateriaSource(void);

		AMateria*	getStock(int idx) const;

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
};

#endif
