/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:21:53 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:21:59 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.hpp"

Contact::Contact() {}
Contact::~Contact() {}

// GET
int		Contact::get_index() {
	return (this->index);
}

std::string	Contact::get_firstName() {
	return (this->firstName);
}

std::string Contact::get_lastName() {
	return (this->lastName);
}

std::string Contact::get_phoneNumber() {
	return (this->phoneNumber);
}

// SET
void Contact::set_index(int index) {
	this->index = index;
}

void Contact::set_firstName(std::string firstName) {
	this->firstName = firstName;
}

void Contact::set_lastName(std::string lastName) {
	this->lastName = lastName;
}

void Contact::set_phoneNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}
