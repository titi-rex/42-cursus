/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:14:11 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/14 19:26:34 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	IMateriaSource*	src = new MateriaSource();
	AMateria*			tmp;

	std::cout<< "-----------------" << std::endl;
	src->learnMateria(new Ice());
	std::cout<< "-----------------" << std::endl;
	src->learnMateria(new Cure());
	std::cout<< "-----------------" << std::endl;
	std::cout<< "-----------------" << std::endl;

	tmp = new Ice();
	src->learnMateria(tmp);
	src->learnMateria(tmp);
	std::cout<< "-----------------" << std::endl;
	std::cout<< "-----------------" << std::endl;
	
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");



	std::cout<< "-----------------" << std::endl;
	std::cout<< "-----------------" << std::endl;
	tmp = src->createMateria("ice");
	std::cout<< "-----------------" << std::endl;
	me->equip(tmp);
	me->equip(tmp);
	std::cout<< "-----------------" << std::endl;
	tmp = src->createMateria("cure");
	std::cout<< "-----------------" << std::endl;
	me->equip(tmp);
	std::cout<< "-----------------" << std::endl;
	tmp = src->createMateria("ice");
	std::cout<< "-----------------" << std::endl;
	me->equip(tmp);
	std::cout<< "-----------------" << std::endl;
	tmp = src->createMateria("ice");
	std::cout<< "-----------------" << std::endl;
	me->equip(tmp);
	std::cout<< "-----------------" << std::endl;
	tmp = src->createMateria("cure");
	std::cout<< "-----------------" << std::endl;
	me->equip(tmp);
	delete tmp;
	std::cout<< "-----------------" << std::endl;
	std::cout<< "-----------------" << std::endl;

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
	bob->use(0, *me);
	bob->unequip(0);

	std::cout<< "-----------------" << std::endl;
	
	std::cout<< "-----------------" << std::endl;
	std::cout<< "-----------------" << std::endl;

	delete bob;
	delete me;
	delete src;

	return (0);
}
