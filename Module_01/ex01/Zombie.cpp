/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:39:58 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/04 17:32:29 by qbeukelm         ###   ########.fr       */
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

std::string		Zombie::toString(int value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}
