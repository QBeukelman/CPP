/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:59:13 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/04/04 11:12:44 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string newName) {
	std::cout << "" << std::endl;
	this->name = newName;
	this->health = DEFAULT_HEALTH;
	this->energy = DEFAULT_ENERGY;
	this->damage = DEFAULT_DAMAGE;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "" << std::endl;
	this->health = other.health;
	this->energy = other.energy;
	this->damage = other.damage;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "" << std::endl;
	if (this != &other) {
		this->health = other.health;
		this->energy = other.energy;
		this->damage = other.damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
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

void	ClapTrap::attack(const std::string& target) {
	if (this->energy < 1) {
		std::cout
			<< this->name
			<< C_RED
			<< " is out of energy. Energy: "
			<< this->energy
			<< RESET_COLOR
			<< std::endl;
		return ;
	}
	if (this->health < 1) {
		std::cout
			<< this->name
			<< C_RED
			<< " has no health. Health: "
			<< this->health
			<< RESET_COLOR
			<< std::endl;
		return ;
	}
	
	this->energy -= 1;
	std::cout
		<< this->name
		<< C_GREEN
		<< " attacks "
		<< target
		<< " causing "
		<< toString(this->damage)
		<< " points of damage!"
		<< RESET_COLOR
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount > this->health) {
		this->health = 0;
	} else {
		this->health -= amount;
	}

	if (this->health <= 0) {
		std::cout
		<< this->name
		<< C_RED
		<< " has no health. Health: "
		<< this->health
		<< RESET_COLOR
		<< std::endl;
	}

	std::cout
		<< this->name
		<< C_GREEN
		<< " takes damage of amount: "
		<< amount
		<< ". Remaining health: "
		<< this->health
		<< RESET_COLOR
		<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy < 1) {
		std::cout
			<< this->name
			<< C_RED
			<< " is out of energy. Energy: "
			<< this->energy
			<< RESET_COLOR
			<< std::endl;
		return ;
	}
	if (this->health < 1) {
		std::cout
			<< this->name
			<< C_RED
			<< " has no health. Health: "
			<< this->health
			<< RESET_COLOR
			<< std::endl;
		return ;
	}

	this->energy -= 1;
	this->health += amount;
	std::cout
		<< this->name
		<< C_GREEN
		<< " repaired with amount: "
		<< amount
		<< ". Current health is: "
		<< this->health
		<< RESET_COLOR
		<< std::endl;
}

std::string		ClapTrap::toString(int value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}
