
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
	private:
		std::string		type;

	public:
		// Default Constructor
		Weapon();
		// Parameteized Constructor
		Weapon(const std::string& type);
		// Copy Constructer
		Weapon(const Weapon& other);
		// Copy Assignment Operator
		Weapon& operator=(const Weapon& other);
		// Destructor
		~Weapon();
		
		// Member Functions
		void				setType(const std::string& newType);
		const std::string&	getType() const;
};

#endif
