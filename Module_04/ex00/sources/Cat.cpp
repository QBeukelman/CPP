/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/12 16:11:56 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/04/16 20:24:59 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "iostream"

Cat::Cat() {
	std::cout << "Cat default constructor." << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& other) {
	std::cout << "Cat copy constructor." << std::endl;
	*this = other;
}

Cat	&Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator." << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor." << std::endl;
}

void Cat::makeSound() const {
	std::cout
		<< C_BLUE
		<< "Cat Meouwww..."
		<< RESET_COLOR
		<< std::endl;	
}
