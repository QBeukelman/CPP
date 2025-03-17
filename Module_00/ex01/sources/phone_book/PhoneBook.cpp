/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:22:03 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:22:05 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.hpp"

PhoneBook::PhoneBook() : currentIndex(0) {}
PhoneBook::~PhoneBook() {}

static Contact	add_contactField(Contact contact, ContactFields field, std::string value) {

	switch (field) {
		case FIRST_NAME:
			contact.set_firstName(value);
		case LAST_NAME:
			contact.set_lastName(value);
		case PHONE_NUMBER:
			contact.set_phoneNumber(value);
		case INDEX: default:
			return (contact);
	}
	return (contact);
}

void	PhoneBook::add() {
	int				index;
	std::string		input;
	Contact			contact;

	while (1) {
		std::cout << C_BLUE << "add\t" << RESET_COLOR << "first name:\t";
		getline(std::cin, input);
		contact = add_contactField(contact, FIRST_NAME, input);

		std::cout << C_BLUE << "add\t" << RESET_COLOR << "last name:\t";
		getline(std::cin, input);
		contact = add_contactField(contact, LAST_NAME, input);

		std::cout << C_BLUE << "add\t" << RESET_COLOR << "phone number:\t";
		getline(std::cin, input);
		contact = add_contactField(contact, PHONE_NUMBER, input);

		break ;
	}

	index = get_contactIndex();
	contact.set_index(index);
	contacts[index] = contact;
	currentIndex++;

	std::cout << C_GREEN << ADDED_CONTACT << RESET_COLOR << "\n\n";
}

void	PhoneBook::search() {
	std::string		input;
	int				index;

	if (this->contacts[0].get_firstName().empty()) {
		std::cout << EMPTY_BOOK << "\n";
		return ;
	}

	std::cout << C_BLUE << "search\t" << RESET_COLOR << SEARCH_PROMPT << "\t";
	getline(std::cin, input);
	index = input[0] - 48 - 1;

	if (index >= 0 && index <= 7 && !this->contacts[index].get_firstName().empty()) {
		write_contact(this->contacts[index]);
	} else {
		std::cout << C_RED << INVALID_INDEX << RESET_COLOR << "\n\n";
	}
}
