/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:14:11 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/28 15:21:01 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	IMateriaSource*	src = new MateriaSource();
	AMateria*		tmp;

	std::clog<< "-----------------" << std::endl;
	src->learnMateria(new Ice());
	std::clog<< "-----------------" << std::endl;
	src->learnMateria(new Cure());
	std::clog<< "-----------------" << std::endl;
	std::clog<< "-----------------" << std::endl;

	tmp = new Ice();
	src->learnMateria(tmp);
	src->learnMateria(tmp);
	std::clog<< "-----------------" << std::endl;
	std::clog<< "-----------------" << std::endl;
	
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");


	std::clog<< "-----------------" << std::endl;
	std::clog<< "-----------------" << std::endl;
	tmp = src->createMateria("ice");
	std::clog<< "-----------------" << std::endl;
	me->equip(tmp);
	me->equip(tmp);
	std::clog<< "-----------------" << std::endl;
	tmp = src->createMateria("cure");
	std::clog<< "-----------------" << std::endl;
	me->equip(tmp);
	std::clog<< "-----------------" << std::endl;
	tmp = src->createMateria("ice");
	std::clog<< "-----------------" << std::endl;
	me->equip(tmp);
	std::clog<< "-----------------" << std::endl;
	tmp = src->createMateria("ice");
	std::clog<< "-----------------" << std::endl;
	me->equip(tmp);
	std::clog<< "-----------------" << std::endl;
	tmp = src->createMateria("cure");
	std::clog<< "-----------------" << std::endl;
	me->equip(tmp);
	delete tmp;
	
	std::clog<< "-----------------" << std::endl;
	std::clog<< "-----------------" << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);

	me->unequip(3);
	me->unequip(4);
	me->use(0, *bob);
	
	std::clog<< "-----------------" << std::endl;

	bob->use(0, *me);
	bob->unequip(0);
	
	std::clog<< "-----------------" << std::endl;
	std::clog<< "-----------------" << std::endl;

	delete bob;
	delete me;
	
	delete src;

	return (0);
}
