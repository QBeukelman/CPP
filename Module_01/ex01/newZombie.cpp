/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:19:09 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:19:11 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*		Zombie::newZombie(std::string name) {
	return new Zombie(name);
}

Zombie*		Zombie::zombieHorde(int N, std::string name) {
	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		horde[i].setName(name + std::to_string(i));
	}
	return (horde);
}
