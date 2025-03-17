/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:15:19 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:15:24 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define ZOMBIE_COUNT 10
#define ZOMBIE_NAME "Zombie_"

int main(void) {
	int		i;
	
	Zombie* horde = Zombie::zombieHorde(ZOMBIE_COUNT, ZOMBIE_NAME);
	write_line();
	
	i = 0;
	while (i < ZOMBIE_COUNT) {
		const bool 			assertion = horde[i].getName() == (ZOMBIE_NAME + std::to_string(i));
		const std::string	message = horde[i].getName();

		assert_with_message(assertion, message);
		i++;
	}

	write_divider();
	delete[] horde;
	horde = nullptr;

	write_divider();
	assert_with_message((horde == nullptr), "Horde deleted");
	write_line();
	
	return (0);
}
