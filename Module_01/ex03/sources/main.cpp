/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:14:59 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/03/14 17:44:55 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon/Weapon.hpp"
#include "human/HumanA.hpp"
#include "human/HumanB.hpp"

int		main(int argc, char **argv) {
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return 0;
}
