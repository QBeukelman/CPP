/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:15:19 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/08 22:00:02 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define ZOMBIE_COUNT 10
#define ZOMBIE_NAME "Zombie_"

void		write_line(void) { std::cout << std::endl; }
void		write_divider(void) { std::cout << std::endl << "---------------------\n\n"; }

int main(void) {
	int		i;
	
	Zombie* horde = zombieHorde(ZOMBIE_COUNT, ZOMBIE_NAME);
	write_line();
	
	i = 0;
	while (i < ZOMBIE_COUNT) {
		const bool 			assertion = horde[i].getName() == (ZOMBIE_NAME + horde[i].toString(i));
		const std::string	message = horde[i].getName();

		assert_with_message(assertion, message);
		i++;
	}

	write_divider();
	delete[] horde;
	horde = NULL;

	write_divider();
	assert_with_message((horde == NULL), "Horde deleted");
	write_line();
	
	return (0);
}
