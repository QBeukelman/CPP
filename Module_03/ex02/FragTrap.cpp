/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:16:27 by quentin           #+#    #+#             */
/*   Updated: 2025/04/18 09:36:52 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap() : ClapTrap() {
    std::cout
		<< "Default FragTrap constructor."
		<< std::endl;
	this->name = "Default FragTrap";
	this->health = FRAG_DEFAULT_HEALTH;
	this->energy = FRAG_DEFAULT_ENERGY;
	this->damage = FRAG_DEFAULT_DAMAGE;
}

FragTrap::FragTrap(std::string newName) {
	std::cout
		<< newName
		<< " FragTrap parameterised constructor."
		<< std::endl;
	this->name = newName;
	this->health = FRAG_DEFAULT_HEALTH;
	this->energy = FRAG_DEFAULT_ENERGY;
	this->damage = FRAG_DEFAULT_DAMAGE;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap() {
	std::cout
		<< other.name
		<< " FragTrap copy constructor."
		<< std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	std::cout
		<< other.name
		<< " FragTrap copy assignment operator."
		<< std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout
		<< this->name
		<< " FragTrap destructor."
		<< std::endl;
}

void	FragTrap::highFiveGuys() {
		if (this->energy < 1) {
		std::cout
			<< "❌ "
			<< C_BLUE
			<< this->name
			<< RESET_COLOR
			<< " FragTrap HighFive"
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
			<< " FragTrap HighFive"
			<< C_RED
			<< " has no health. Health: ["
			<< this->health
			<< "]"
			<< RESET_COLOR
			<< std::endl;
		return ;
	}
	std::cout
		<< "🙌 "
		<< C_BLUE
		<< this->name
		<< RESET_COLOR
		<< " FragTrap High Five Guys!"
		<< std::endl;
}

void	FragTrap::attack(const std::string &target) {
	if (this->energy < 1) {
		std::cout
			<< "❌ "
			<< C_BLUE
			<< this->name
			<< RESET_COLOR
			<< " FragTrap attacks"
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
			<< " FragTrap attacks"
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
		<< " FragTrap attacks "
		<< C_BLUE
		<< target
		<< RESET_COLOR
		<< " causing ["
		<< toString(this->damage)
		<< "] points of damage!"
		<< std::endl;
}
