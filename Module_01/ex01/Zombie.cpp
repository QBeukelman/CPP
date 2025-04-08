/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 21:39:58 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/08 21:59:48 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define ANNOUNCE " BraiiiiiiinnnzzzZ..."

Zombie::Zombie() : name("Default Zombie") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {
	std::cout << C_BLUE << name << C_RED << " has been destroyed" << RESET_COLOR << std::endl;
}

std::string	Zombie::getName(void) const {
	return (this->name);
}

void	Zombie::setName(std::string newName) {
	this->name = newName;
}

void	Zombie::announce(void) {
	std::cout << C_BLUE << this->name << RESET_COLOR << ANNOUNCE << std::endl;
}

std::string		Zombie::toString(int value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}
