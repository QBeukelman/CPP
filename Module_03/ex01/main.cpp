/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:19:41 by quentin           #+#    #+#             */
/*   Updated: 2025/04/18 10:26:26 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

void	write_line(void) { std::cout << std::endl; }
void	write_divider(void) { std::cout << std::endl << "---------------------\n\n"; }

int		main(void) {

	write_divider();
	{
		ScavTrap frodo = ScavTrap("Frodo");

		write_line();
		frodo.setDamage(2);
		frodo.attack("Sauron");
		frodo.takeDamage(2);
		frodo.beRepaired(1);
		frodo.guardGate();
		write_line();
	}
	write_divider();
	{
		ScavTrap frodo = ScavTrap("Frodo");

		write_line();
		frodo.setHealth(0);
		frodo.guardGate();
		write_line();
	}
	write_divider();
}
