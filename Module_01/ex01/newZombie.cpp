/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:19:09 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/08 21:59:20 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name) {
	Zombie *zombie = new (Zombie);

	zombie->setName(name);
	return (zombie);
}