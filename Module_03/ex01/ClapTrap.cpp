/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:31:40 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/04/18 09:31:53 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <sstream>

ClapTrap::ClapTrap() {
	std::cout
		<< "Default ClapTrap"
		<< " constructor." 
		<< std::endl;
	this->name = "Default ClapTrap";
	this->health = DEFAULT_HEALTH;
	this->energy = DEFAULT_ENERGY;
	this->damage = DEFAULT_DAMAGE;
}

ClapTrap::ClapTrap(const std::string newName) {
	std::cout
		<< newName
		<< " ClapTrap parameterised constructor." 
		<< std::endl;
	this->name = newName;
	this->health = DEFAULT_HEALTH;
	this->energy = DEFAULT_ENERGY;
	this->damage = DEFAULT_DAMAGE;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout
		<< other.name
		<< " ClapTrap copy constructor."
		<< std::endl;
	this->health = other.health;
	this->energy = other.energy;
	this->damage = other.damage;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& other) {
	std::cout
		<< other.name
		<< " ClapTrap copy assignment operator."
		<< std::endl;
	if (this != &other) {
		this->health = other.health;
		this->energy = other.energy;
		this->damage = other.damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout
		<< this->name
		<< " ClapTrap destructor."
		<< std::endl;
}

std::string	ClapTrap::getName(void) {
	return (this->name);
}

void	ClapTrap::setName(std::string newName) {
	this->name = newName;
}

int		ClapTrap::getHealth(void) {
	return (this->health);
}

void	ClapTrap::setHealth(int newHealth) {
	this->health = newHealth;
}

int		ClapTrap::getEnergy(void) {
	return (this->energy);
}

void	ClapTrap::setEnergy(int newEnergy) {
	this->energy = newEnergy;
}

int		ClapTrap::getDamage(void) {
	return (this->damage);
}

void	ClapTrap::setDamage(int newDamage) {
	this->damage = newDamage;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->energy < 1) {
		std::cout
			<< "❌ "
			<< C_BLUE
			<< this->name
			<< RESET_COLOR
			<< " ClapTrap attacks"
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
			<< " ClapTrap attacks"
			<< C_RED
			<< " has no health. Health: ["
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
		<< " ClapTrap attacks "
		<< C_BLUE
		<< target
		<< RESET_COLOR
		<< " causing ["
		<< toString(this->damage)
		<< "] points of damage!"
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	unsigned int	healthBefore = this->health;

	if (amount > this->health) {
		this->health = 0;
	} else {
		this->health -= amount;
	}

	if ((health >= 0) && (healthBefore != this->health)) {
		std::cout
			<< "💥 "
			<< C_BLUE
			<< this->name
			<< RESET_COLOR
			<< " ClapTrap takes damage: ["
			<< amount
			<< "]. Health: ["
			<< this->health
			<< "]"
			<< std::endl;
	}	

	if (this->health <= 0) {
		std::cout
			<< "❌ "
			<< C_BLUE
			<< this->name
			<< RESET_COLOR
			<< " ClapTrap takes damage "
			<< C_RED
			<< " has no health. Health: ["
			<< this->health
			<< "]"
			<< RESET_COLOR
			<< std::endl;
		return ;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy < 1) {
		std::cout
			<< "❌ "
			<< C_BLUE
			<< this->name
			<< RESET_COLOR
			<< " ClapTrap be repaired"
			<< C_RED
			<< " is out of energy. Energy: ["
			<< this->energy
			<< "]"
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
			<< " ClapTrap be repaired"
			<< C_RED
			<< " has no health. Health: ["
			<< this->health
			<< "]"
			<< RESET_COLOR
			<< std::endl;
		return ;
	}

	this->energy -= 1;
	this->health += amount;
	std::cout
		<< "🔋 "
		<< C_BLUE
		<< this->name
		<< RESET_COLOR
		<< " ClapTrap repaired: ["
		<< amount
		<< "]. Health: ["
		<< this->health
		<< "]"
		<< std::endl;
}

std::string		ClapTrap::toString(int value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}
