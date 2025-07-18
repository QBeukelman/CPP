/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 07:53:00 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/07/18 11:05:26 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>

// -------------------------------------------------------------: Constructors
AForm::AForm()
	: name(DEFAULT_FORM_NAME),
	  grade(MIN_GRADE),
	  isSigned(DEFAULT_IS_SIGNED),
	  gradeToSign(MAX_GRADE),
	  gradeToExecute(MAX_GRADE) {
	std::cout << "AForm default constructor." << std::endl;
}

AForm::AForm(std::string newName, int newGrade, int newGradeToSign, int newGradeToExecute)
	: name(newName),
	  grade(newGrade),
	  isSigned(DEFAULT_IS_SIGNED),
	  gradeToSign(newGradeToSign),
	  gradeToExecute(newGradeToExecute) {

	if (newGrade < MAX_GRADE || newGradeToSign < MAX_GRADE || newGradeToExecute < MAX_GRADE) {
		throw GradeTooHighException();
	} else if (newGrade > MIN_GRADE || newGradeToSign > MIN_GRADE || newGradeToExecute > MIN_GRADE) {
		throw GradeTooLowException();
	}

	std::cout
		<< "AForm parameterised constructor for "
		<< newName << "."
		<<std::endl;
}

AForm::AForm(const AForm& other)
	: name(other.name),
	  grade(other.grade),
	  isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign),
	  gradeToExecute(other.gradeToExecute) {
	std::cout
		<< "AForm copy constructor for "
		<< other.getName() << "."
		<< std::endl;
}

// Copy assignment not present because of const members.
AForm& AForm::operator=(const AForm& other) {
	std::cout
		<< "AForm copy assignment operator (deleted). Returning `*this` and other, "
		<< other.getName()
		<< " has not been assigned."
		<< std::endl;
	return (*this);
}

AForm::~AForm() {
	std::cout
		<< "Form destructor for "
		<< this->getName() << "."
		<< std::endl;
}


// -------------------------------------------------------------: Menbers
std::ostream& operator<<(std::ostream& out, const AForm& form) {
	out
		<< "Form \"" << form.getName()
		<< "\", grade: " << form.getGrade()
	    << ", signed: " << (form.getSigned() ? "yes" : "no")
	    << ", grade required to sign: " << form.getGradeToSign()
	    << ", grade required to execute: " << form.getGradeToExecute();
	return (out);
}

std::string	AForm::getName() const {
	return (this->name);
}

int	AForm::getGrade() const {
	return (this->grade);
}

bool	AForm::getSigned() const {
	return (this->isSigned);
}

int	AForm::getGradeToSign() const {
	return (this->gradeToSign);
}

int AForm::getGradeToExecute() const {
	return (this->gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() < MAX_GRADE) {
		throw GradeTooHighException();
	}
	else if (bureaucrat.getGrade() > MIN_GRADE) {
		throw GradeTooLowException();
	}
	else if (bureaucrat.getGrade() > this->gradeToSign) {
		throw GradeTooLowException();
	} else {
		this->isSigned = true;
	}
}

bool	AForm::getIsSigned() const {
	return (this->isSigned);
}

/*
	If Bureaucrat grade is lower than form requirement,
	throw TooLowException.
*/
void	AForm::execute(Bureaucrat const &executor) const {
	if (this->getGradeToExecute() < executor.getGrade()) {
		throw GradeTooLowException();
	}
}


// -------------------------------------------------------------: Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
	return ("Exception: AForm grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Exception: AForm grade is too low.");
}
