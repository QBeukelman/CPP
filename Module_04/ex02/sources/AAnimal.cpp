/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/16 16:35:46 by quentin       #+#    #+#                 */
/*   Updated: 2025/04/16 16:37:41 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "../include/AAnimal.hpp"
#include "iostream"

AAnimal::AAnimal() {
	std::cout << "Animal default constructor." << std::endl;
	this->type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal& other) {
	std::cout << "AAnimal copy constructor." << std::endl;
	*this = other;
}

AAnimal	&AAnimal::operator=(const AAnimal& other) {
	std::cout << "AAnimal copy assignment operator." << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal Destructor." << std::endl;
}

std::string AAnimal::getType() const {
	return (this->type);
}

void	AAnimal::setType(const std::string newType) {
	this->type = newType;
}

void	AAnimal::makeSound() const {
	std::cout
		<< C_BLUE
		<< "Animal generic sound..."
		<< RESET_COLOR
		<< std::endl;	
}
