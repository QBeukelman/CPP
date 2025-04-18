/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:19:49 by quentin           #+#    #+#             */
/*   Updated: 2025/04/18 09:30:56 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout
		<< "Default ScavTrap constructor."
		<< std::endl;
	this->name = "Default ScavTrap";
	this->health = SCAV_DEFAULT_HEALTH;
	this->energy = SCAV_DEFAULT_ENERGY;
	this->damage = SCAV_DEFAULT_DAMAGE;
}

ScavTrap::ScavTrap(std::string newName) {
	std::cout
		<< newName
		<< " ScavTrap parameterised constructor."
		<< std::endl;
	this->name = newName;
	this->health = SCAV_DEFAULT_HEALTH;
	this->energy = SCAV_DEFAULT_ENERGY;
	this->damage = SCAV_DEFAULT_DAMAGE;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap() {
	std::cout
		<< other.name
		<< " ScavTrap copy constructor."
		<< std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	std::cout
		<< other.name
		<< " ScavTrap copy assignment operator."
		<< std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout
		<< this->name
		<< " ScavTrap destructor."
		<< std::endl;
}

void	ScavTrap::guardGate() {
		if (this->energy < 1) {
		std::cout
			<< "❌ "
			<< C_BLUE
			<< this->name
			<< RESET_COLOR
			<< " ScavTrap GateKeperMode"
			<< C_RED
			<< " is out of energy. Energy: ["
			<< this->energy
			<< ']'
			<< RESET_COLOR
			<< std::endl;
		return ;
	}
	if (this->health < 1) {
		std::cout
			<< "❌ "
			<< C_BLUE
			<< this->name
			<< RESET_COLOR
			<< " ScavTrap GateKeperMode"
			<< C_RED
			<< " has no health. Health: ["
			<< this->health
			<< "]"
			<< RESET_COLOR
			<< std::endl;
		return ;
	}
	std::cout
		<< "💂 "
		<< C_BLUE
		<< this->name
		<< RESET_COLOR
		<< " ScavTrap is now in GateKeper mode"
		<< std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (this->energy < 1) {
		std::cout
			<< "❌ "
			<< C_BLUE
			<< this->name
			<< RESET_COLOR
			<< " ScavTrap attacks"
			<< C_RED
			<< " is out of energy. Energy: ["
			<< this->energy
			<< ']'
			<< RESET_COLOR
			<< std::endl;
		return ;
	}
	if (this->health < 1) {
		std::cout
			<< "❌ "
			<< C_BLUE
			<< this->name
			<< RESET_COLOR
			<< " ScavTrap attacks"
			<< C_RED
			<< " ScavTrap has no health. Health: ["
			<< this->health
			<< "]"
			<< RESET_COLOR
			<< std::endl;
		return ;
	}
	
	this->energy -= 1;
	std::cout
		<< "🥊 "
		<< C_BLUE
		<< this->name
		<< RESET_COLOR
		<< " ScavTrap attacks "
		<< C_BLUE
		<< target
		<< RESET_COLOR
		<< " causing ["
		<< toString(this->damage)
		<< "] points of damage!"
		<< std::endl;
}
