/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 21:39:58 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:19:38 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define ANNOUNCE " BraiiiiiiinnnzzzZ..."

Zombie::Zombie() : name("Default Zombie") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {
	std::cout << C_BLUE << name << C_RED << " has been destroyed" << RESET_COLOR << std::endl;
}

std::string Zombie::getName(void) const {
	return (name);
}

void	Zombie::setName(std::string newName) {
	name = newName;
}

void		Zombie::announce(void) {
	std::cout << C_BLUE << name << RESET_COLOR << ANNOUNCE << std::endl;
}
