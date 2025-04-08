/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/14 16:51:47 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/04/08 22:05:38 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../weapon/Weapon.hpp"
#include "HumanA.hpp"

Weapon defaultWeapon("Default Weapon");
HumanA::HumanA() : name("Default HumanA"), weapon(defaultWeapon) {}

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {}

std::string	HumanA::getName(void) const {
	return (this->name);
}

void	HumanA::setName(std::string newName) {
	this->name = newName;
}

Weapon&	HumanA::getWeapon() const {
	return (this->weapon);
}

void	HumanA::setWeapon(Weapon& newWeapon) {
	this->weapon = newWeapon;
}

void	HumanA::attack() const {
	std::cout
		<< C_BLUE
		<< name
		<< RESET_COLOR
		<< " attacks with their "
		<< C_YELLOW
		<< weapon.getType()
		<< RESET_COLOR
		<< std::endl;
}
