/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:20:03 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:20:06 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	Create, name and annouce Zombie
*/
void	randomChump(std::string name) {
	Zombie zombie;

	zombie.setName(name);
	zombie.announce();
}
