/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:04:26 by quentin           #+#    #+#             */
/*   Updated: 2025/07/18 10:55:12 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include <iostream>

// -------------------------------------------------------------: Constructors
Bureaucrat::Bureaucrat() {
	std::cout << "Bureaucrat default constructor." << std::endl;
	this->name = DEFAULT_NAME;
	this->grade = MIN_GRADE;
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) {
std::cout
		<< "Bureaucrat parameterised constructor for "
		<< newName << "."
		<< std::endl;
	if (newGrade < MAX_GRADE) {
		throw GradeTooHighException();
	}
	if (newGrade > MIN_GRADE) {
		throw GradeTooLowException();
	}
	this->name = newName;
	this->grade = newGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	std::cout
		<< "Bureaucrat copy constructor for "
		<< other.getName() << "."
		<< std::endl;
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout
		<< "Bureaucrat copy assignment operator for "
		<< other.getName() << "."
		<< std::endl;
	if (this != &other) {
		this->name = other.name;
		this->grade = other.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout
        << "Bureaucrat destructor for "
        << this->getName() << "."
        << std::endl;
}


// -------------------------------------------------------------: Menbers
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}

std::string Bureaucrat::getName() const {
	return (this->name);
}

int	Bureaucrat::getGrade() const {
	return (this->grade);
}

void	Bureaucrat::incrementGrade() {
	if (this->getGrade() > MAX_GRADE) {
		this->grade--;
	} else {
		throw GradeTooHighException();
	}
}

void	Bureaucrat::decrementGrade() {
	if (this->getGrade() < MIN_GRADE) {
		this->grade++;
	} else {
		throw GradeTooLowException();
	}
}


// -------------------------------------------------------------: Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Exception: Bureaucrat grade is greater than maximum limit of 0");	
} 

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Exception: Bureaucrat grade is less than minimum limit of 150");
}
