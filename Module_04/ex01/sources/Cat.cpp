/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/12 16:11:56 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/04/16 15:36:46 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "iostream"

Cat::Cat() {
	std::cout << "Cat default constructor." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor." << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain); // Deep copy
}

Cat	&Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator." << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
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
