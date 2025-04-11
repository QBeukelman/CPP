/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:14:59 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/04/11 11:19:24 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon/Weapon.hpp"
#include "human/HumanA.hpp"
#include "human/HumanB.hpp"
#include <iostream>

void		write_line(void) { std::cout << std::endl; }
void		write_divider(void) { std::cout << std::endl << "---------------------\n\n"; }

int		main(void) {

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
