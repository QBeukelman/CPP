/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 21:39:58 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:20:40 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define ANNOUNCE " BraiiiiiiinnnzzzZ..."

Zombie::Zombie() : name("Default Zombie") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {
	std::cout << C_BLUE << name << C_RED << " has been destroyed" << RESET_COLOR << std::endl;
}

void	Zombie::announce(void) {
	std::cout << C_BLUE << this->name << RESET_COLOR << ANNOUNCE << std::endl;
}

void	Zombie::setName(std::string newName) {
	this->name = newName;
}
