/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:44:06 by quentin           #+#    #+#             */
/*   Updated: 2025/07/18 10:56:15 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>

// -------------------------------------------------------------: Constructors
Form::Form()
	: name(DEFAULT_FORM_NAME),
	  grade(MIN_GRADE),
	  isSigned(DEFAULT_IS_SIGNED),
	  gradeToSign(MAX_GRADE),
	  gradeToExecute(MAX_GRADE) {
	std::cout << "Form default constructor." << std::endl;
}

Form::Form(std::string newName, int newGrade, int newGradeToSign, int newGradeToExecute)
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
		<< "Form parameterised constructor for "
		<< newName << "."
		<<std::endl;
}

Form::Form(const Form& other)
	: name(other.name),
	  grade(other.grade),
	  isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign),
	  gradeToExecute(other.gradeToExecute) {
	std::cout
		<< "Form copy constructor for "
		<< other.getName() << "."
		<< std::endl;
}

// Copy assignment not present because of const members.
Form& Form::operator=(const Form& other) {
	std::cout
		<< "Form copy assignment operator (deleted). Returning `*this` and other, "
		<< other.getName()
		<< " has not been assigned."
		<< std::endl;
	return (*this);
}

Form::~Form() {
	std::cout
		<< "Form destructor for "
		<< this->getName() << "."
		<< std::endl;
}


// -------------------------------------------------------------: Menbers
std::ostream& operator<<(std::ostream& out, const Form& form) {
	out
		<< "Form \"" << form.getName()
		<< "\", grade: " << form.getGrade()
	    << ", signed: " << (form.getSigned() ? "yes" : "no")
	    << ", grade required to sign: " << form.getGradeToSign()
	    << ", grade required to execute: " << form.getGradeToExecute();
	return (out);
}

std::string	Form::getName() const {
	return (this->name);
}

int		Form::getGrade() const {
	return (this->grade);
}

bool	Form::getSigned() const {
	return (this->isSigned);
}

int		Form::getGradeToSign() const {
	return (this->gradeToSign);
}

int		Form::getGradeToExecute() const {
	return (this->gradeToExecute);
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
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


// -------------------------------------------------------------: Exceptions
const char* Form::GradeTooHighException::what() const throw() {
	return ("Exception: Form grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Exception: Form grade is too low.");
}
