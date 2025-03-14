/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:51:47 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/03/14 17:43:21 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../weapon/Weapon.hpp"
#include "HumanA.hpp"

Weapon defaultWeapon("Default Weapon");
HumanA::HumanA() : name("Default HumanA"), weapon(defaultWeapon) {}

HumanA::HumanA(std::string name, Weapon weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {
	std::cout << "HumanA destroyed\n";
}

std::string		HumanA::getName(void) const {
	return (this->name);
}

void			HumanA::setName(std::string newName) {
	this->name = newName;
}

Weapon&			HumanA::getWeapon() const {
	return (this->weapon);
}

void			HumanA::setWeapon(Weapon& newWeapon) {
	this->weapon = newWeapon;
}

void		HumanA::attack() const {
	std::cout
		<< name
		<< " attacks with their "
		<< weapon.getType()
		<< std::endl;
}
