/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:18:37 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/08 22:04:31 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("Default") {}

Weapon::Weapon(const std::string& type) : type(type) {}

Weapon::~Weapon() {}

const std::string&	Weapon::getType() const {
	return (this->type);
}

void   Weapon::setType(const std::string& newType) {
	this->type = newType;
}
