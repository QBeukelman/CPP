/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/16 16:40:20 by quentin       #+#    #+#                 */
/*   Updated: 2025/04/16 16:55:35 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/AAnimal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "iostream"

#define TEST_COUNT 8

static void	write_line(void) { std::cout << std::endl; }

static void	write_divider(std::string message) { 
	std::cout 
		<< "--------------"
		<< message
		<< "-------------- \n\n"; 
}

int	main() {
	AAnimal	*animals[TEST_COUNT];
	Brain	*brain;

	write_line();
	write_divider("Simple tests");
	
	for (int i = 0; i < TEST_COUNT; i++) {
		if (i % 2) {
			animals[i] = new Dog();
			std::cout
				<< "Type: " << C_BLUE << animals[i]->getType() << RESET_COLOR << std::endl;
		} else {
			animals[i] = new Cat();
			std::cout
				<< "Type: " << C_BLUE << animals[i]->getType() << RESET_COLOR << std::endl;
		}
	}

	write_line();
	write_divider("Brain tests");

	// Add some ideas
	brain = &animals[0]->getBrain();
	brain->setIdea(0, "What does a cat think about?");
	brain->setIdea(1, "To eat or not to eat?");

	std::cout << "Idea of animals[0]: " << C_BLUE << brain->getIdea(0) << RESET_COLOR << std::endl;
	std::cout << "Idea of animals[0]: " << C_BLUE << brain->getIdea(1) << RESET_COLOR << std::endl;

	// Test a deep copy
	animals[5] = animals[0];
	std::cout << "Deep copy test" << std::endl;
	std::cout << "Idea of animals[5]: " << C_BLUE << animals[5]->getBrain().getIdea(0) << RESET_COLOR << std::endl;
	std::cout << "Idea of animals[5]: " << C_BLUE << animals[5]->getBrain().getIdea(1) << RESET_COLOR << std::endl;

	// Delete all animals
	write_line();
	for (int i = 0; i < TEST_COUNT; i++) {
		if (i == 5)
			continue ;
		delete animals[i];
		write_line();
	}

	write_divider("Test makeSound()");
	{
		// const AAnimal* animal = new AAnimal(); // Pure virtual, can not be created.
        const AAnimal* dog = new Dog();
        const AAnimal* cat = new Cat();

		write_line();
		std::cout
			<< "Type: " << C_BLUE << dog->getType() << RESET_COLOR << std::endl;
		dog->makeSound();
		
		write_line();
		std::cout
			<< "Type: " << C_BLUE << cat->getType() << RESET_COLOR << std::endl;
		cat->makeSound();
		
		write_line();
		delete cat;
		delete dog;
		write_line();
	}
	write_divider("");
}
