/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:21:53 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/04 14:40:11 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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

std::string Contact::get_nickname() {
	return (this->nickname);
}

std::string Contact::get_phoneNumber() {
	return (this->phoneNumber);
}

std::string Contact::get_darketSecret() {
	return (this->darkestSecret);
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

void Contact::set_nickname(std::string nickname) {
	this->nickname = nickname;
}

void Contact::set_phoneNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::set_darkestSecret(std::string darkestSecret) {
	this->darkestSecret = darkestSecret;
}
