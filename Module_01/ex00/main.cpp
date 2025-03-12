
#include "Zombie.hpp"

static void write_line(void) { std::cout << std::endl; }
static void write_divider(void) { std::cout << std::endl << "---------------------" << std::endl << std::endl; }

int main(void) {
	
	write_line();
	Zombie*	heapZombie = Zombie::newZombie("HeapZombie");
	heapZombie->announce();
	delete (heapZombie);

	write_divider();
	Zombie::randomChump("StackZombie");
	write_line();
	
	return (0);
}
