/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/13 13:44:06 by quentin       #+#    #+#                 */
/*   Updated: 2025/06/13 15:18:08 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
#include "iostream"

// -------------------------------------------------------------: Constructors
Form::Form() {
	std::cout << "Form default constructor." << std::endl;
	this->name = DEFAULT_FORM_NAME;
	this->grade = MIN_GRADE;
	this->isSigned = DEFAULT_IS_SIGNED;
	this->gradeForSignature = MAX_GRADE;
	this->gradeForExecution = MAX_GRADE;
}

Form::Form(std::string newName, int newGrade, int newGradeForSigniture, int newGradeForExecution) {
	std::cout
		<< "Form parameterised constructor for "
		<< newName << "."
		<<std::endl;
	if (newGrade < MAX_GRADE) {
		throw GradeTooHighException();
	}
	if (newGrade > MIN_GRADE) {
		throw GradeTooLowException();
	}
	this->name = newName;
	this->grade = newGrade;
	this->isSigned = DEFAULT_IS_SIGNED;
	this->gradeForSignature = newGradeForSigniture;
	this->gradeForExecution = newGradeForExecution;
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
		this->gradeForSignature = other.gradeForSignature;
		this->gradeForExecution = other.gradeForExecution;
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

int	Form::getGradeForSigniture() const {
	return (this->gradeForSignature);
}

int Form::getGradeForExecution() const {
	return (this->gradeForExecution);
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() < MAX_GRADE) {
		throw GradeTooHighException();
	}
	else if (bureaucrat.getGrade() > MIN_GRADE) {
		throw GradeTooLowException();
	}
	else if (bureaucrat.getGrade() > this->gradeForSignature) {
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
