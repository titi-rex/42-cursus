/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:52:44 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/13 20:17:20 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FLOOR_H__
# define _FLOOR_H__
#include <string>
# include "AMateria.hpp"

class AMateria;

class Floor 
{
	
	private	:
		AMateria*	_m;
		Floor*		_next;
		static int	_n_node;

	public	:

		Floor(void);
		Floor(const Floor& src);
		Floor&	operator=(const Floor& src);
		~Floor(void);

		Floor(AMateria* m);

		void	addNode(AMateria* m);
		int		getNNode(void) const;
		void	setNNode(int n);

};

#endif
