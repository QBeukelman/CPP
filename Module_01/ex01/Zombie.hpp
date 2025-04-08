
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <memory>
#include <cassert>
#include <sstream>

#define C_YELLOW "\033[1;33m"
#define C_RED "\x1B[1;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define RESET_COLOR "\033[0m"

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
		std::string			toString(int value);
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);
Zombie*	zombieHorde(int N, std::string name);
void	assert_with_message(bool assertion, const std::string& message);

#endif
