/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:52:41 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/07/18 11:18:43 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

class AForm;

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm default constructor." << std::endl;
	this->target = DEFAULT_TARGET;
}

// Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &newTarget)
	: AForm(
		"Robotomy Request Form",
		MIN_GRADE,
		SIGN_ROBOTOMY_FORM,
		EXC_ROBOTOMY_FORM) {
	std::cout
		<< "RobotomyRequestForm constructor for: "
		<< newTarget << "."
		<< std::endl;
	this->target = newTarget;
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
	std::cout
		<< "RobotomyRequestForm copy constructor for "
		<< other.getName() << "."
		<< std::endl;
	*this = other;
}

// Copy Assignment Constructor
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout
		<< "RobotomyRequestForm copy assignment operator for "
		<< other.getName() << "."
		<< std::endl;
	if (this != &other) {
		this->target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout
		<< "RobotomyRequestForm destructor for "
		<< this->getName() << "."
		<< std::endl;
}


// -------------------------------------------------------------: Menbers
std::string		RobotomyRequestForm::getTarget() const {
	return (this->target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	AForm::execute(executor);

	if (getIsSigned() == false) {
		throw AForm::GradeTooLowException();
	} else {
		std::cout
			<< C_BLUE
			<< "Robotomy makes random drilling noises..."
			<< RESET_COLOR
			<< std::endl;
		
		std::srand(std::time(0)); // Seed with current time -> rand() not the same
		if (rand() % 2 == 0) {
			std::cout
				<< C_BLUE
				<< "Robotomization SUCCESS: "
				<< this->getTarget()
				<< " has been Robotomized."
				<< RESET_COLOR
				<< std::endl;
		} else {
			std::cout
				<< C_BLUE
				<< "Robotomization FAILURE: "
				<< this->getTarget()
				<< " could not be Robotomized."
				<< RESET_COLOR
				<< std::endl;
		}
	}
}
