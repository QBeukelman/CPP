/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:19:52 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:24:21 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
