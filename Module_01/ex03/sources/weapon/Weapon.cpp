
#include "Weapon.hpp"

Weapon::Weapon() : type("Default") {
	std::cout << "Default Constructor\n";
}

Weapon::Weapon(const std::string& type) : type(type) {
	std::cout << "Parameterized Constructor\n";
}

Weapon::~Weapon() {
	std::cout << "Destructor\n";
}

void   Weapon::setType(const std::string& newType) {
	type = newType;
}

const std::string&     Weapon::getType() const {
	return type;
}
