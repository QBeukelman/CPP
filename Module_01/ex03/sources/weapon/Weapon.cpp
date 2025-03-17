/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:18:37 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:18:40 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("Default") {}

Weapon::Weapon(const std::string& type) : type(type) {}

Weapon::~Weapon() {}

void   Weapon::setType(const std::string& newType) {
	type = newType;
}

const std::string&     Weapon::getType() const {
	return type;
}
