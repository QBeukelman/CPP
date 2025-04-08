/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:19:59 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:20:01 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	Return a new Zombie, to be used outside of the function scope
*/
Zombie*	newZombie(std::string name) {
	Zombie *zombie = new (Zombie);

	zombie->setName(name);
	return (zombie);
}
