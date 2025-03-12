/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 21:39:58 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/07 09:56:21 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define ANNOUNCE " BraiiiiiiinnnzzzZ..."

// Default constructor
Zombie::Zombie() : name("Default Zombie") {}

// Parameterized Constructor
Zombie::Zombie(std::string name) : name(name) {}

// Deconstructor
Zombie::~Zombie() {
	std::cout << C_BLUE << name << C_RED << " has been destroyed" << RESET_COLOR << std::endl;
}

// Getter
std::string Zombie::getName(void) const {
	return (name);
}

// Setter
void	Zombie::setName(std::string newName) {
	name = newName;
}

void		Zombie::announce(void) {
	std::cout << C_BLUE << name << RESET_COLOR << ANNOUNCE << std::endl;
}
