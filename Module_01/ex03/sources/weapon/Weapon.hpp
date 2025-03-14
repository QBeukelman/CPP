
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
	private:
		std::string		type;

	public:
		Weapon();
		Weapon(const std::string& type);
		~Weapon();
		
		// Member Functions
		void				setType(const std::string& newType);
		const std::string&	getType() const;
};

#endif
