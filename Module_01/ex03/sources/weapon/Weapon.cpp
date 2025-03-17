
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
