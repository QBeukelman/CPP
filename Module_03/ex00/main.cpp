/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:59:23 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/04/18 10:27:39 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

void	write_line(void) { std::cout << std::endl; }
void	write_divider(void) { std::cout << std::endl << "---------------------\n\n"; }

int main(void) {
	write_divider();
	{
		ClapTrap frodo = ClapTrap("Frodo");
		ClapTrap sauron = ClapTrap("Sauron");

		write_line();
		frodo.setDamage(2);
		frodo.attack("Sauron");
		frodo.takeDamage(5);
		frodo.takeDamage(5);
		frodo.attack("Sauron");
		write_line();
	}
	write_divider();
	{
		ClapTrap frodo = ClapTrap("Frodo");

		write_line();
		frodo.attack("Sauron");
		frodo.attack("Sauron");
		frodo.attack("Sauron");
		frodo.attack("Sauron");
		frodo.attack("Sauron");
		frodo.attack("Sauron");
		frodo.attack("Sauron");
		frodo.attack("Sauron");
		frodo.attack("Sauron");
		frodo.attack("Sauron");
		frodo.attack("Sauron");
		frodo.beRepaired(10);
		write_line();
	}
	write_divider();
	{
		ClapTrap frodo = ClapTrap("Frodo");

		write_line();
		frodo.takeDamage(10);
		frodo.takeDamage(1);
		frodo.beRepaired(10);
		write_line();
	}
	write_divider();
	{
		ClapTrap fordo = ClapTrap("Frodo");

		write_line();
		fordo.beRepaired(100);
		fordo.beRepaired(1000);
		fordo.beRepaired(10000);
		fordo.beRepaired(100000);
		write_line();
	}
	write_divider();

    return (0);
}
