/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/12 16:26:09 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/04/16 15:37:06 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "iostream"

Dog::Dog() {
	std::cout << "Dog default constructor." << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor." << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain); // Deep copy
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignemnt operator." << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor." << std::endl;
	delete(this->brain);
}

void	Dog::makeSound() const {
	std::cout
		<< C_BLUE
		<< "Dog Groofff..."
		<< RESET_COLOR
		<< std::endl;
}

Brain&	Dog::getBrain() const {
	return (*this->brain);
}
