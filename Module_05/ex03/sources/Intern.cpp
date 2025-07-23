/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:24:40 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/07/23 09:16:17 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

#include <iostream>
#include <map>
#include <functional>

// Default Constructor
Intern::Intern() {
	std::cout << "Intern default constructor." << std::endl;
}

// Copy Constructor
Intern::Intern(const Intern& other) {
	std::cout
		<< "Intern copy constructor."
		<< std::endl;
	*this = other;
}

// Copy Assignment Constructor
Intern& Intern::operator=(const Intern& other) {
	std::cout
		<< "Intern copy assignment operator."
		<< std::endl;
	if (this != &other) {}
	return (*this);
}

Intern::~Intern() {
	std::cout
		<< "Intern destructor."
		<< std::endl;
}


// -------------------------------------------------------------: Menbers
AForm*	Intern::PresidentialPardon(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::RobotomyRequest(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::ShrubberyCreation(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeForm(const std::string &name, const std::string &target) {
	static const std::map<std::string, std::function<AForm*(const std::string&)>> formCreators = {
		{ "shrubbery creation", [this](const std::string& t) { return this->ShrubberyCreation(t); } },
		{ "robotomy request",   [this](const std::string& t) { return this->RobotomyRequest(t); } },
		{ "presidential pardon", [this](const std::string& t) { return this->PresidentialPardon(t); } }
	};

	auto it = formCreators.find(name);
	if (it != formCreators.end()) {
		std::cout
			<< C_BLUE
			<< "Intern creates "
			<< name
			<< RESET_COLOR
			<< std::endl;
		return (it->second(target));
	}

	throw Intern::InternFormException();
}

const char* Intern::InternFormException::what() const throw() {
	return ("Exception: Intern does not know the given form.");	
}
