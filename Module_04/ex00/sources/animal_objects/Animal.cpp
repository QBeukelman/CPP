/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:07:22 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/04/12 16:59:44 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../animal_headers/Animal.hpp"
#include "iostream"

Animal::Animal() {
	std::cout << "Animal default constructor." << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "Animal copy constructor." << std::endl;
	*this = other;
}

Animal	&Animal::operator=(const Animal& other) {
	std::cout << "Animal copy assignment operator." << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal Destructor." << std::endl;
}

std::string Animal::getType() const {
	return (this->type);
}

void	Animal::setType(const std::string newType) {
	this->type = newType;
}

void	Animal::makeSound() const {
	std::cout
		<< C_BLUE
		<< "Animal generic sound..."
		<< RESET_COLOR
		<< std::endl;	
}
