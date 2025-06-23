/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/13 13:44:06 by quentin       #+#    #+#                 */
/*   Updated: 2025/06/23 16:55:33 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>

// -------------------------------------------------------------: Constructors
Form::Form() {
	std::cout << "Form default constructor." << std::endl;
	this->name = DEFAULT_FORM_NAME;
	this->grade = MIN_GRADE;
	this->isSigned = DEFAULT_IS_SIGNED;
	this->gradeToSign = MAX_GRADE;
	this->gradeToExecute = MAX_GRADE;
}

Form::Form(std::string newName, int newGrade, int newGradeToSign, int newGradeToExecute) {
	if (newGrade < MAX_GRADE || newGradeToSign < MAX_GRADE || newGradeToExecute < MAX_GRADE) {
		throw GradeTooHighException();
	} else if (newGrade > MIN_GRADE || newGradeToSign > MIN_GRADE || newGradeToExecute > MIN_GRADE) {
		throw GradeTooLowException();
	} else {
		this->name = newName;
		this->grade = newGrade;
		this->isSigned = DEFAULT_IS_SIGNED;
		this->gradeToSign = newGradeToSign;
		this->gradeToExecute = newGradeToExecute;
	}
	std::cout
		<< "Form parameterised constructor for "
		<< newName << "."
		<<std::endl;
}

Form::Form(const Form& other) {
	std::cout
		<< "Form copy constructor for "
		<< other.getName() << "."
		<< std::endl;
	*this = other;
}

Form &Form::operator=(const Form& other) {
	std::cout
		<< "Form copy assignment operator for "
		<< other.getName() << "."
		<< std::endl;

	if (this != &other) {
		this->name = other.name;
		this->grade = other.grade;
		this->isSigned = other.isSigned;
		this->gradeToSign = other.gradeToSign;
		this->gradeToExecute = other.gradeToExecute;
	}
	return (*this);
}

Form::~Form() {
	std::cout
		<< "Form destructor for "
		<< this->getName() << "."
		<< std::endl;
}


// -------------------------------------------------------------: Menbers
std::ostream& operator<<(std::ostream& out, const Form& form) 
{
	out << form.getName() << ", form grade " << form.getGrade() << std::endl;
	return (out);
}

std::string	Form::getName() const {
	return (this->name);
}

int	Form::getGrade() const {
	return (this->grade);
}

bool	Form::getSigned() const {
	return (this->isSigned);
}

int	Form::getGradeToSign() const {
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const {
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
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Exception: Form grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Exception: Form grade is too low.");
}
