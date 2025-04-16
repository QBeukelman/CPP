/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/16 16:46:10 by quentin       #+#    #+#                 */
/*   Updated: 2025/04/16 16:49:47 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "iostream"

Cat::Cat() {
	std::cout << "Cat default constructor." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& other) {
	std::cout << "Cat copy constructor." << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain); // Deep copy
}

Cat	&Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator." << std::endl;
	AAnimal::operator=(other);
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor." << std::endl;
	delete(this->brain);
}

void Cat::makeSound() const {
	std::cout
		<< C_BLUE
		<< "Cat Meouwww..."
		<< RESET_COLOR
		<< std::endl;	
}

Brain	&Cat::getBrain() const {
	return (*this->brain);
}
