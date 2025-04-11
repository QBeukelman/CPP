/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:39:58 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/11 11:12:03 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

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
