/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/14 14:14:59 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/03/16 15:13:18 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "weapon/Weapon.hpp"
#include "human/HumanA.hpp"
#include "human/HumanB.hpp"

static void write_line(void) { std::cout << std::endl; }
static void write_divider(void) { std::cout << std::endl << "---------------------\n\n"; }

int		main(int argc, char **argv) {

	write_line();
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	write_divider();
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	write_divider();
	{
		HumanB jim("Jim");
		jim.attack();
	}
	write_line();

	return 0;
}
