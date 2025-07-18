/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:24:49 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/07/18 11:08:55 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

class AForm;

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm default constructor." << std::endl;
	this->target = DEFAULT_TARGET;
}

// Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &newTarget)
	: AForm(
		"Presidential Pardon Form",
		MIN_GRADE,
		SIGN_PARDON_FORM,
		EXC_PARDON_FORM) {
	std::cout
		<< "PresidentialPardonForm constructor for: "
		<< newTarget << "."
		<< std::endl;
	this->target = newTarget;
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
	std::cout
		<< "PresidentialPardonForm copy constructor for "
		<< other.getName() << "."
		<< std::endl;
	*this = other;
}

// Copy Assignment Constructor
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout
		<< "PresidentialPardonForm copy assignment operator for "
		<< other.getName() << "."
		<< std::endl;
	if (this != &other) {
		this->target = other.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout
		<< "PresidentialPardonForm destructor for "
		<< this->getName() << "."
		<< std::endl;
}


// -------------------------------------------------------------: Menbers
std::string		PresidentialPardonForm::getTarget() const {
	return (this->target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	AForm::execute(executor);

	if (getIsSigned() == false) {
		throw AForm::GradeTooLowException();
	} else {
		std::cout
			<< C_BLUE
			<< this->getTarget()
			<< " has been pardoned by Zaphod Beeblebrox."
			<< RESET_COLOR
			<< std::endl;
	}
}
