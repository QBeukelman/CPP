
#ifndef ZOMBIE.HPP
#define ZOMBIE.HPP

#include <string>

class Zombie {
	private:
		std::string		name;

	public:
		// Constructor
		Zombie();
		// Destructor
		~Zombie();

		Zombie*		newZombie(std::string name);
		void		randomChump(std::string name);
};

#endif
