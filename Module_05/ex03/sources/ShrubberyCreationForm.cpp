/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 08:21:33 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/07/18 11:18:58 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

class AForm;

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm default constructor." << std::endl;
	this->target = DEFAULT_TARGET;
}

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &newTarget)
	: AForm(
		"Shrubbery Creation Form",
		MIN_GRADE,
		SIGN_SHRUBBERY_FORM,
		EXC_SHRUBBERY_FORM) {
	std::cout
		<< "ShrubberyCreationForm constructor for: "
		<< newTarget << "."
		<< std::endl;
	this->target = newTarget;
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
	std::cout
		<< "ShrubberyCreationForm copy constructor for "
		<< other.getName() << "."
		<< std::endl;
	*this = other;
}

// Copy Assignment Constructor
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout
		<< "ShrubberyCreationForm copy assignment operator for "
		<< other.getName() << "."
		<< std::endl;
	if (this != &other) {
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout
		<< "ShrubberyCreationForm destructor for "
		<< this->getName() << "."
		<< std::endl;
}


// -------------------------------------------------------------: Menbers
std::string		ShrubberyCreationForm::getTarget() const {
	return (this->target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	AForm::execute(executor);

	if (getIsSigned() == false) {
		throw AForm::GradeTooLowException();
	} else {
		std::ofstream	file(target.c_str());
		if (!file) {
			std::cout
				<< "Error opening file: "
				<< executor.getName();
			return ;
		}
		file << ASCII_TREE;
		file.close();
		std::cout
			<< C_BLUE
			<< target
			<< " file was successfully created."
			<< RESET_COLOR
			<< std::endl;
	}
}

