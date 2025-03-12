
#include "Weapon.hpp"

Weapon::Weapon() : type("Default") {
	std::cout << "Default Constructor\n";
}

Weapon::Weapon(const std::string& type) : type(type) {
	std::cout << "Parameterized Constructor\n";
}

Weapon::Weapon(const Weapon& other) : type(other.type) {
	std::cout << "Copy Constructor\n";
}

Weapon& Weapon::operator=(const Weapon& other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "Copy Assignment Operator\n";
	return *this;
}

void	Weapon::setType(const std::string& newType) {
	type = newType;
}

const std::string&	Weapon::getType() const {
	return type;
}

Weapon::~Weapon() {
	std::cout << "Destructor\n";
}
