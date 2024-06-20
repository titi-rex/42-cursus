/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:07:19 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/28 13:09:10 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << i->getType() << " : ";
	i->makeSound(); //will output the cat sound!
	std::cout << j->getType() << " : ";
	j->makeSound();
	std::cout << meta->getType() << " : ";
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	
	std::cout << wrongmeta->getType() << " : ";
	wrongmeta->makeSound();
	std::cout << wrongcat->getType() << " : ";
	wrongcat->makeSound(); 

	delete wrongmeta;
	delete wrongcat;
	return (0);
}