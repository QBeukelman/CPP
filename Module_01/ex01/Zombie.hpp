
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <memory>
#include <cassert>
#include "../utils/utils.hpp"

class Zombie {
	private:
		std::string		name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void				setName(std::string newName);
		std::string			getName(void) const;
		void				announce(void);
		static Zombie*		newZombie(std::string name);
		static void			randomChump(std::string name);
		static Zombie*		zombieHorde(int N, std::string name);
};

void	assert_with_message(bool assertion, const std::string& message);

#endif
