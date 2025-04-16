/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/16 16:28:22 by quentin       #+#    #+#                 */
/*   Updated: 2025/04/16 16:33:37 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain default constructor." << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor." << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain& other) {
	std::cout << "Brain copy assignment constructor." << std::endl;
	if (this != &other)
		for (int i = 0; i < IDEAS_MAX; i++)
			this->ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor." << std::endl;
}

void	Brain::setIdea(int index, std::string idea) {
	if (index >= 0 && index < IDEAS_MAX)
		this->ideas[index] = idea;
}

std::string	Brain::getIdea(int index) {
	if (index >= 0 && index < IDEAS_MAX)
		return this->ideas[index];
	return (this->ideas[0]);
}
