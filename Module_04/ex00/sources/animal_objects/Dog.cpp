/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:26:09 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/04/12 16:59:20 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../animal_headers/Dog.hpp"
#include "iostream"

Dog::Dog() {
	std::cout << "Dog default constructor." << std::endl;
}

Dog::Dog(const Dog& other) {
	std::cout << "Dog copy constructor." << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignemnt operator." << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor." << std::endl;
}

void	Dog::makeSound() const {
	std::cout
		<< C_BLUE
		<< "Dog Groofff..."
		<< RESET_COLOR
		<< std::endl;
}
