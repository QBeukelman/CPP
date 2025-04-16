/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/12 16:33:50 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/04/14 17:29:17 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "animal_headers/Animal.hpp"
#include "animal_headers/Cat.hpp"
#include "animal_headers/Dog.hpp"
#include "iostream"

void	write_line(void) { std::cout << std::endl; }
void	write_divider(void) { std::cout << std::endl << "---------------------\n\n"; }

int	main() {
	write_divider();
	{
		Animal	animal = Animal();
		Cat		cat = Cat();
		Dog 	dog = Dog();
	
		write_line();
		animal.makeSound();
		cat.makeSound();
		dog.makeSound();
		write_line();
	}
	write_divider();
	{
		const Animal* animal = new Animal();
		const Animal* cat = new Cat();
		const Animal* dog = new Dog();
		
		write_line();
		std::cout << "Cat type: " << cat->getType() << std::endl;
		std::cout << "Dog type: " << dog->getType() << std::endl;
		cat->makeSound();
		dog->makeSound();
		animal->makeSound();
		write_line();
	}
	write_divider();
}
