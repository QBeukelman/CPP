/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:11:58 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/03/14 17:45:55 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../weapon/Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB() : name("Default HumanB") {}

// Weapon is optional, starts as nullptr
HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {
	std::cout << "HumanA destroyed\n";
}

std::string		HumanB::getName(void) const {
	return (this->name);
}

void			HumanB::setName(std::string newName) {
	this->name = newName;
}

Weapon*			HumanB::getWeapon() const {
	return (this->weapon);
}

void			HumanB::setWeapon(Weapon& newWeapon) {
	this->weapon = &newWeapon;
}

void		HumanB::attack() const {
	if (weapon)	{
		std::cout
			<< name
			<< " attacks with their "
			<< weapon->getType()
			<< std::endl;
	} else {
		std::cout
			<< name
			<< " has no weapon to attack with"
			<< std::endl;
	}
};
