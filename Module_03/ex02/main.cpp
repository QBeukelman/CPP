/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/11 00:14:33 by quentin       #+#    #+#                 */
/*   Updated: 2025/04/11 00:35:21 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

void	write_line(void) { std::cout << std::endl; }
void	write_divider(void) { std::cout << std::endl << "---------------------\n\n"; }

int     main(void) {

	write_divider();
	{
		FragTrap frodo = FragTrap("Frodo");

		write_line();
		frodo.setDamage(2);
		frodo.attack("Sauron");
		frodo.takeDamage(2);
		frodo.beRepaired(1);
		frodo.highFiveGuys();
		write_line();
	}
	write_divider();
	{
		FragTrap frodo = FragTrap("Frodo");

		write_line();
		frodo.setHealth(0);
		frodo.highFiveGuys();
		write_line();
	}
	write_divider();
}
