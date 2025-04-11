/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:11:58 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/04/11 11:18:31 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../weapon/Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() : name("Default HumanB") {}

// Weapon is optional, starts as nullptr
HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {}

std::string	HumanB::getName(void) const {
	return (this->name);
}

void	HumanB::setName(std::string newName) {
	this->name = newName;
}

Weapon*	HumanB::getWeapon() const {
	return (this->weapon);
}

void	HumanB::setWeapon(Weapon& newWeapon) {
	this->weapon = &newWeapon;
}

void	HumanB::attack() const {
	std::cout
		<< C_BLUE
		<< name
		<< RESET_COLOR;

	if (weapon)	{
		std::cout
			<< " attacks with their "
			<< C_YELLOW
			<< weapon->getType()
			<< RESET_COLOR
			<< std::endl;
	} else {
		std::cout
			<< " has no weapon to attack with..."
			<< std::endl;
	}
};
